#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>

int *weapon[7];

pthread_t tid1,tid2;


void *menu(void *argv){
	int choice,jml;
	char sjt[15];
	while(1){
		system("clear");
		printf("1. Lihat Stock\n");
		printf("2. Tambah Stock\n");
		scanf("%d",&choice);
		if(choice == 1){

		}
		else if(choice == 2){
			printf("Masukkan nama senjata dan jumlah yang ditambah :\n");
			scanf("%s %d", sjt  ,&jml);
			char a[10]="MP4A1";
			if((strcmp(sjt,"MP4A1") == 0)){
					
				printf("MP4A1anjing\n");
				sleep(5);

			}
			else if(sjt == "PM2-V1"){

			}
			else if(sjt == "SPR-3"){

			}
			else if(sjt == "SS2-V5"){

			}
			else if(sjt == "SPG1-V3"){

			}
			else if(sjt == "MINE"){

			}
			else printf("Senjata Tidak Ditemukan\n");
		}
	}
	return NULL;
}

int main(){
	system("clear");
	key_t key = 1234;
	int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
	*weapon = shmat(shmid, NULL, 0);
	//memset(*weapon, 0,sizeof(*weapon[7]));
    pthread_create(&(tid1), NULL, &menu, NULL);

	shmdt(weapon);
    shmctl(shmid, IPC_RMID, NULL);

    pthread_join(tid1, NULL);
}