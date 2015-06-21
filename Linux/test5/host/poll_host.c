/* poll_host.c */
#include <stdio.h>
#include <poll.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "uart_api.h"

int main(void) 
{
    int fds[SEL_FILE_NUM], recv_fd, maxfd;
    char buff[BUFFER_SIZE];
	fd_set inset,tmp_inset;
	struct timeval tv;
	unsigned loop = 1;
	int res, real_read, i;
	
	if ((recv_fd = open(RECV_FILE_NAME, O_CREAT|O_WRONLY, 0644)) < 0)
	{   
		perror("open");
		return 1;
	}
  	
	fds[0] = STDIN_FILENO; /* stdin */ 
	if((fds[1] = open_port(HOST_COM_PORT)) < 0)  
	{
		perror("open_port");
		return 1;
	}
	
	if(set_com_config(fds[1], 115200, 8, 'N', 1) < 0) /* open serial port */ 
	{
		perror("set_com_config");
		return 1;
	}

	struct pollfd *pollFd;
	pollFd = calloc(2, sizeof(struct pollfd));     
	if (pollFd == NULL)
	{
		perror("calloc");  
		exit(-1);
	}
	for (i = 0; i < 2; i++)
	{
		pollFd[i].fd = fds[i];
		pollFd[i].events = POLLIN;
	}
	
	printf("Input some words(enter 'quit' to exit):\n");
	while (loop)
	{
		res = poll(pollFd,2,TIME_DELAY * 1000);
		
		switch(res)
		{
			case -1:
			{
				perror("poll");
				loop = 0;
			}
			break;
			
			case 0: /* Timeout */
			{
				perror("poll time out");
				loop = 0;
			}
			break;
			
			default:
			{
				for (i = 0; i < SEL_FILE_NUM; i++)
				{
					if (pollFd[i].revents&POLLIN)
					{
						memset(buff, 0, BUFFER_SIZE);
						real_read = read(fds[i], buff, BUFFER_SIZE);
						if ((real_read < 0) && (errno != EAGAIN))
						{
							loop = 0;
						}
						else if (!real_read)
						{
							close(fds[i]);
						}
						else
						{	
							buff[real_read] = '\0';
							if (i == 0)
							{
								write(fds[1], buff, strlen(buff));
								printf("Input some words(enter 'quit' to exit):\n");
							}
							else if (i == 1)
							{
								write(recv_fd, buff, real_read);
							}
							if (strncmp(buff, "quit", 4) == 0)
							{
								loop = 0;
							}
						}
					} 
				} /* end of for */
			} /* end of default */
		} /* end of switch */ 
	} /* end of while */

	close(recv_fd);	
  	return 0;
}
