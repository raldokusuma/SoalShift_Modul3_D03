#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

void main()
{
        key_t key = 1234;
        int *value;

        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        value = shmat(shmid, NULL, 0);

        printf("Ifah : %d\n", *value);
	*value = 10;

        sleep(5);

        printf("Fina: %d\n", *value);
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}
