#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "mylock.h"

#define MAXLEN 10
#define ALPHABET 1
#define ALPHABET_START 'a'
#define COUNT_OF_ALPHABET 26
#define DIGIT 2
#define DIGIT_START '0'
#define COUNT_OF_DIGIT 10
#define SIGN_TYPE ALPHABET

const char *fifo_file = "./myfifo";
char buff[MAXLEN];

int product(void)
{
    int fd;
    unsigned int sign_type,sign_start,sign_count,size;
    static unsigned int counter = 0;

    if((fd = open(fifo_file, O_CREAT|O_RDWR|O_APPEND, 0644)) < 0){
        printf("Open fifo file error\n");
        exit(1);
    }
    sign_type = SIGN_TYPE;
    switch(sign_type)
    {
        case ALPHABET:
            sign_start = ALPHABET_START;
            sign_count = COUNT_OF_ALPHABET;
        break;
        case DIGIT:
            sign_start = DIGIT_START;
            sign_count = COUNT_OF_DIGIT;
        break;
        default:
        return -1;
    }
    sprintf(buff, "%c", (sign_start + counter));
    counter = (counter + 1) % sign_count;
    lock_set(fd,F_WRLCK);
    if((size = write(fd,buff,strlen(buff))) < 0)
    {
        printf("Producter:write error\n");
        return -1;
    }
    lock_set(fd,F_UNLCK);
    close(fd);
    return 0;
}

int main(int argc, char **argv)
{
    int time_step = 1;
    int time_life = 10;
    if(argc > 1)
    {
        sscanf(argv[1],"%d",&time_step);
    }
    if(argc > 2)
    {
        sscanf(argv[2],"%d",&time_life);
    }
    while(time_life--)
    {
        if(product() < 0)
            break;
        sleep(time_step);
    }
    exit(EXIT_SUCCESS);
}
