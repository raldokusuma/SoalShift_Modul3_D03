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
	int choice;
	int jml;
	char sjt[15];
	while(1){
		system("clear");
		choice=0;
		printf("1. Lihat Stock\n");
		printf("2. Tambah Stock\n");
		scanf("%d",&choice);
		if(choice == 1){
			system("clear");
			printf("STOCK SENJATA\n\n");
			printf("MP4A1 %d\n",*weapon[1]);
			printf("PM2-V1 %d\n",*weapon[2]);
			printf("SPR-3 %d\n",*weapon[3]);
			printf("SS2-V5 %d\n",*weapon[4]);
			printf("SPG1-V3 %d\n",*weapon[5]);
			printf("MINE %d\n",*weapon[6]);
			sleep(4);
		}
		else if(choice == 2){
			printf("Masukkan nama senjata dan jumlah yang ditambah :\n");
			scanf("%s %d", sjt,&jml);
			if((strcmp(sjt,"MP4A1") == 0)){
				*weapon[1]+=jml;
			}
			else if((strcmp(sjt,"PM2-V1") == 0)){
				*weapon[2]+=jml;
			}
			else if((strcmp(sjt,"SPR-3") == 0)){
				*weapon[3]+=jml;
			}
			else if((strcmp(sjt,"SS2-V5") == 0)){
				*weapon[4]+=jml;
			}
			else if((strcmp(sjt,"SPG1-V3") == 0)){
				*weapon[5]+=jml;
			}
			else if((strcmp(sjt,"MINE") == 0)){
				*weapon[6]+=jml;
			}
			else printf("Senjata Tidak Ditemukan\n");
		}
	}
	return NULL;
}

int main(){
	int i=0;
	system("clear");
	key_t key[7];
	for(i=0;i<=7;i++) {key[i]=i+20;}

	int shmid[7];
	for(i=0;i<=7;i++){
		shmid[i] = shmget(key[i], sizeof(int), IPC_CREAT | 0666);
	}
	for(i=0;i<=7;i++){
	weapon[i] = shmat(shmid[i], NULL, 0);
	}

	memset(*weapon, 0,sizeof(*weapon));
    pthread_create(&(tid1), NULL, &menu, NULL);

	shmdt(weapon);
	for(i=0;i<=7;i++) shmctl(shmid[i], IPC_RMID, NULL);

    pthread_join(tid1, NULL);
}