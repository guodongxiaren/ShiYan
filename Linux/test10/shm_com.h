/* shm_com.h */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define SHM_BUFF_SZ   2048
struct shared_use_st
{
    int pid;
    char buffer[SHM_BUFF_SZ];
};
