#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#define MAXSIZE 128 

const char *file1 = "testfile.txt";
const char *file2 = "file2.txt";

int main(int argc,char **argv){
    int fd,fd2;
    if((fd = open(file1,O_CREAT|O_RDWR|O_TRUNC,0644)) == -1){
        if(errno!=EEXIST){
            perror("open failed\n");
            exit(EXIT_FAILURE);
        }
    }
    if((fd2 = open(file2,O_CREAT|O_WRONLY|O_TRUNC,0644)) == -1){
        if(errno!=EEXIST){
            perror("open failed\n");
            exit(EXIT_FAILURE);
        }
    }
    int size;
    char buf[MAXSIZE];
    if(fgets(buf,MAXSIZE,stdin) == NULL){
        perror("fgets failed\n");
        exit(EXIT_FAILURE);
    }
    if(write(fd,buf,strlen(buf)) < 0){
        perror("写入fd失败\n");
        exit(EXIT_FAILURE);
    }
    lseek(fd,0,SEEK_SET);
    printf("开始拷贝%s到%s中...\n",file1,file2);
    while((size = read(fd,buf,strlen(buf))) == MAXSIZE){
        if(write(fd2,buf,size) < 0){
            perror("写入fd2失败\n");
            exit(EXIT_FAILURE);
        }
    }
        printf("拷贝了%d个字符\n",size);
        if(size < 0){
            perror("read failed\n");
            exit(EXIT_FAILURE);
        }else{
            if(write(fd2,buf,strlen(buf)) < 0){
                perror("read failed\n");
                exit(EXIT_FAILURE);
            }
        }
    printf("拷贝完成\n");
}

