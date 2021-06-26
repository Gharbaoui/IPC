#include "mem.h"

int main()
{
    key_t   key;
    int     shmid;
    char    *shm;
    char    *s;

    key = ftok("uniqe", 0);
    shmid = shmget(key, SH_SIZE, 0666 | IPC_CREAT);
    shm = shmat(shmid, NULL, 0);
   
    printf("%s\n", shm);
    *shm = '-';
    shmdt(shm);
}
