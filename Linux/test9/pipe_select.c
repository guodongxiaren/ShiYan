#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>

#define FIFO1 "in1"
#define FIFO2 "in2"
#define MAX_BUFFER_SIZE 1024
#define IN_FILES 3
#define TIME_DELAY 60
#define MAX(a,b) ((a>b)?a:b)

int main()
{
    int fds[IN_FILES];
    char buf[MAX_BUFFER_SIZE];
    int i, res, real_read, maxfd;
    struct timeval tv;
    fd_set inset, tmp_inset;

    fds[0] = 0;

    /* 创建两个有名管道 */
    if (access(FIFO1, F_OK) == -1)
    {
        if ((mkfifo(FIFO1, 0666) < 0) && (errno != EEXIST))
        {
            printf("Cannot create fifo file\n");
            exit(1);
        }
    }
    if (access(FIFO2, F_OK) == -1)
    {
        if ((mkfifo(FIFO2, 0666) < 0) && (errno != EEXIST))
        {
            printf("Cannot create fifo file\n");
            exit(1);
        }
    }
    /* 以只读非阻塞方式打开两个管道文件 */
    if ((fds[1] = open(FIFO1, O_RDONLY|O_NONBLOCK)) < 0)
    {
        printf("Open in1 error\n");
        exit(1);
    }
    if ((fds[2] = open(FIFO2, O_RDONLY|O_NONBLOCK)) < 0)
    {
        printf("Open in2 error\n");
        exit(1);
    }
    /* 取出两个fd中较大者 */
    maxfd = MAX(MAX(fds[0], fds[1]), fds[2]);
    FD_ZERO(&inset);
    for (i = 0; i < IN_FILES; i++)
    {
       FD_SET(fds[i], &inset);
    }
    FD_SET(0, &inset);

    tv.tv_sec = TIME_DELAY;
    tv.tv_usec = 0;

    while (FD_ISSET(fds[0], &inset) || FD_ISSET(fds[1], &inset) 
            || FD_ISSET(fds[2], &inset))
    {
        tmp_inset = inset;
        res = select(maxfd + 1, &tmp_inset, NULL, NULL, &tv);
        switch (res)
        {
            case -1: 
                printf("Select error\n");
                return 1;
            case 0: 
                printf("Time out\n");
                return 1;
            default : 
                for (i = 0; i < IN_FILES; i++)
                {
                    if (FD_ISSET(fds[i], &tmp_inset))
                    {
                        memset(buf, 0, MAX_BUFFER_SIZE);
                        real_read = read(fds[i], buf, MAX_BUFFER_SIZE);
                        if (real_read < 0)
                        {
                            if (errno != EAGAIN)
                            {
                                return 1;
                            }
                        }
                        else if(!real_read)
                        {
                            close(fds[i]);
                            FD_CLR(fds[i], &inset);
                        }
                        else // real_read > 0
                        {
                            if (i == 0)
                            {
                                if ((buf[0] == 'q')||(buf[0] == 'Q'))
                                {
                                    return 1;
                                }
                            }
                            else
                            {
                                buf[real_read] = '\0';
                                printf("%s", buf);
                            }
                        }
                    }
                }/* end of for */
        }/* end of switch */
    }/*end of while */

    return 0;
}

