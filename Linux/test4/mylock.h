#ifndef _MYLOCK_H
#define _MYLOCK_H
struct myflock{
    short l_type;
    off_t l_start;
    short l_whence;
    off_t l_len;
    pid_t l_pid;
};
/* lock_set */
int lock_set(int fd,int type){
    struct myflock old_lock,lock;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_type = type;
    lock.l_pid = 1;

    fcntl(fd,F_GETLK,&lock);
    if(lock.l_type != F_UNLCK){
        if(lock.l_type == F_RDLCK){
            printf("Read lock already set by %d\n",lock.l_pid);
        }else if(lock.l_type == F_WRLCK){
            printf("Write lock already set by %d\n",lock.l_pid);
        }
    }
    lock.l_type = type;

    if((fcntl(fd,F_SETLKW,&lock)) < 0){
        printf("Lock failed:type = %d\n",lock.l_type);
        return -1;
    }
    switch(lock.l_type){
        case F_RDLCK: printf("Read lock set by %d\n",getpid());
                      break;
        case F_WRLCK: printf("Write lock set by %d\n",getpid());
                      break;
        case F_UNLCK: printf("Release lock set by %d\n",getpid());
                      return 1;
                      break;
        default:
                      break;
    }
    return 0;
}
#endif
