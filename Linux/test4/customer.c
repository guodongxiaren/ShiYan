#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "mylock.h"

#define MAX_FILE_SIZE 100 * 1024 * 1024   /* 100M */

const char *fifo_file = "./myfifo";
const char *tmp_file = "./tmp";

int customing(const char *myfifo,int need){
    int fd;
    char buff;
    int counter = 0;
    if((fd = open(myfifo,O_RDONLY)) < 0){
        fprintf(stderr,"Function customing error\n");
        return -1;
    }
    printf("Enjoy:");
    // 使fd重置为文件起始位置
    lseek(fd,0,SEEK_SET);
    while(counter < need){
        while((read(fd,&buff,1) == 1)&&(counter < need)){
            fputc(buff,stdout);
            counter++;
        }
    }
    fputs("\n",stdout);
    close(fd);
    return 0;
}

/* myfilecopy()
 * 实现从sour_file 文件的offset偏移处将count个字节复制到dest_file文件
 */
 int myfilecopy(const char *sour_file,const char *dest_file,
               int offset,int count,int copy_mode)
 {
     int in_file,out_file;
     int counter = 0;
     char buff_unit;
     if((in_file = open(sour_file,O_RDONLY|O_NONBLOCK)) < 0){
         fprintf(stderr,"Function myfilecopy error in source file\n");
         return -1;
     }
     if((out_file = open(dest_file,O_CREAT|O_RDWR|O_NONBLOCK,0644)) < 0){
         fprintf(stderr,"Function myfilecopy error in destination file\n");
         return -1;
     }
     lseek(in_file,offset,SEEK_SET);
     while((read(in_file,&buff_unit,1) == 1)&&(counter < count)){
         if(write(out_file,&buff_unit,1)){
             perror("write out_file failed");
             exit(EXIT_FAILURE);
         }
         counter++;
     }
     close(in_file);
     close(out_file);
     return 0;
 }

 /*custom()
  * 实现FIFO消费者
  */
  int custom(int need){
      int fd;
      customing(fifo_file,need);
      if((fd = open(fifo_file,O_RDWR)) < 0){
         fprintf(stderr,"Function custom error in source file\n");
         return -1;
      }
      lock_set(fd,F_WRLCK);
      myfilecopy(fifo_file,tmp_file,need,MAX_FILE_SIZE,0);
      myfilecopy(tmp_file,fifo_file,0,MAX_FILE_SIZE,0);
      lock_set(fd,F_UNLCK);
      unlink(tmp_file);
      close(fd);
      return 0;
  }

  int main(int argc,char **argv){
      int customer_capacity = 10;
      if(argc > 1){
          sscanf(argv[1],"%d",&customer_capacity);
      }
      if(customer_capacity > 0){
          custom(customer_capacity);
      }
      exit(EXIT_SUCCESS);
  }
