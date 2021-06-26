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
    
    memcpy(shm, "hello", 5);
    s = shm + 5;
    *s = 0;
    while (*shm != '-')
        sleep(1);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);
}
