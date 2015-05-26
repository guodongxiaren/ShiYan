#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#include <sys/ipc.h>

#define MYFIFO            "myfifo"     /* 缓冲区有名管道的名字 */
#define BUFFER_SIZE       3            /* 缓冲区的单元数 */
#define UNIT_SIZE         5             /* 每个单元的大小 */
#define RUN_TIME          30            /* 运行时间 */
#define DELAY_TIME_LEVELS     5.0     /* 周期的最大值 */

int fd;
time_t end_time;
sem_t mutex, full, avail;              /* 3个信号量 */



/*生产者线程*/
void *producer(void *arg)
{
     int real_write;
     int delay_time = 0;
     
     while(time(NULL) < end_time)
     {
          delay_time = (int)(rand() * DELAY_TIME_LEVELS/(RAND_MAX) / 2.0) + 1;
          sleep(delay_time);
          /*P操作信号量avail和mutex*/
          sem_wait(&avail);
          sem_wait(&mutex);
          printf("\nProducer: delay = %d\n", delay_time);
          /*生产者写入数据*/
          if ((real_write = write(fd, "hello", UNIT_SIZE)) == -1)
          {
               if(errno == EAGAIN)
               {
                    printf("The FIFO has not been read yet.Please try later\n");
               }
          }
          else
          {
               printf("Write %d to the FIFO\n", real_write);
          }
          
          /*V操作信号量full和mutex*/
          sem_post(&full);
          sem_post(&mutex);
     }     
     pthread_exit(NULL);
}


/* 消费者线程*/
void *customer(void *arg)
{ 
     unsigned char read_buffer[UNIT_SIZE];
     int real_read;
     int delay_time;
     
     while(time(NULL) < end_time)
     {
          delay_time = (int)(rand() * DELAY_TIME_LEVELS/(RAND_MAX)) + 1;
          sleep(delay_time);

          /*P操作信号量full和mutex*/
          sem_wait(&full);
          sem_wait(&mutex);
          memset(read_buffer, 0, UNIT_SIZE);
                    printf("\nCustomer: delay = %d\n", delay_time);

          if ((real_read = read(fd, read_buffer, UNIT_SIZE)) == -1)
          {
               if (errno == EAGAIN)
               {
                   printf("No data yet\n");
               }
          }
          printf("Read %s from FIFO\n", read_buffer);
          /*V操作信号量avail和mutex*/
          sem_post(&avail);
          sem_post(&mutex);
     }
     pthread_exit(NULL);
}

int main()
{
     pthread_t thrd_prd_id,thrd_cst_id;
     pthread_t mon_th_id;
     int ret;
     
     srand(time(NULL));
     end_time = time(NULL) + RUN_TIME;
     /*创建有名管道*/
     if((mkfifo(MYFIFO, O_CREAT|O_EXCL) < 0) && (errno != EEXIST))
     {
          printf("Cannot create fifo\n");
          return errno;
     }               
     /*打开管道*/
     fd = open(MYFIFO, O_RDWR);
     if (fd == -1)
     {
          printf("Open fifo error\n");
          return fd;
     }     
     /*初始化互斥信号量为1*/
     ret = sem_init(&mutex, 0, 1);
     /*初始化avail信号量为N*/
     ret += sem_init(&avail, 0, BUFFER_SIZE);
     /*初始化full信号量为0*/
     ret += sem_init(&full, 0, 0);
     if (ret != 0)
     {
          printf("Any semaphore initialization failed\n");
          return ret;
     }
     /*创建两个线程*/
     ret = pthread_create(&thrd_prd_id, NULL, producer, NULL);
     if (ret != 0)
     {
          printf("Create producer thread error\n");
          return ret;
     }
     ret = pthread_create(&thrd_cst_id, NULL, customer, NULL);
     if(ret != 0)
     {
          printf("Create customer thread error\n");
          return ret;
     }
     pthread_join(thrd_prd_id, NULL);
     pthread_join(thrd_cst_id, NULL);
     close(fd);
     unlink(MYFIFO);
     return 0;
}

