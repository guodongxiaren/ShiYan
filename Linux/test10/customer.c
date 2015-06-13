/* customer.c */
#include "shm_com.h"
#include "sem_com.h"

int main()
{
    void *shared_memory = NULL;
    struct shared_use_st *shm_buff_inst;
    int shmid, semid;
    /* 获得信号量 */
    semid = semget(ftok(".", 'a'),  1, 0666);
    if (semid == -1)
    {    
        perror("Producer is'nt exist");
        exit(1);
    }


    /* 获得共享内存 */
    shmid = shmget(ftok(".", 'b'), sizeof(struct shared_use_st), 0666|IPC_CREAT)
;
    if (shmid == -1)
    {
        perror("shmget");
        exit(1);
    }


    /* 将共享内存地址映射到当前进程地址空间 */
    shared_memory = shmat(shmid, (void*)0, 0); 
    if (shared_memory == (void*)-1)
    {
        perror("shmat");
        exit(1);
    }

    printf("Memory attached at %X\n",(int)shared_memory);

    /* 获得共享内存的映射地址 */
    shm_buff_inst = (struct shared_use_st *)shared_memory;

    do
    {
        sem_p(semid);
        printf("Shared memory was written by process %d :%s",shm_buff_inst->pid,
 shm_buff_inst->buffer);
        if (strncmp(shm_buff_inst->buffer, "quit", 4) == 0) 
        {
            break;
        }
        shm_buff_inst->pid = 0;
        memset(shm_buff_inst->buffer, 0, SHM_BUFF_SZ);
        sem_v(semid);
        sleep(2);
    } while(1);

    /* 删除共享内存到当前进程地址空间中的映射 */
    if (shmdt(shared_memory) == -1)
    {
        perror("shmdt");
        exit(1);
    }
    /* 删除共享内存 */
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl(IPC_RMID)");
        exit(1);
    }
    exit(0);
}
