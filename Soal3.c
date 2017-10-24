#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>


pthread_t tid1, tid2, tid3;
int hplo=100, hpkep=100;

void * menu(void *mmn){
	int choice;
	while(1){
		choice=0;
		printf("Status Lohan    = %d\n",hplo);
		printf("Status Kepiting = %d\n",hpkep);
		printf("\n1. Berimakan lohan\n");
		printf("2. Berimakan kepiting\n");
		scanf("%d", &choice);
		if(choice == 1){
			hplo+=10;
		}
		else if(choice == 2){
			hpkep+=10;
		}
		system("clear");
		if(hplo<=0 || hplo>100 || hpkep<=0 || hpkep>100){
			printf("\n\tGAME OVER\nPELIHARAAN ANDA ADA YANG MATI\n");
			exit(EXIT_SUCCESS);
		}
	}
	return NULL;
}

void* lohan(void *arg){
	
	while(1){
		sleep(10);
		hplo-=15;
		system("clear");

		printf("Status Lohan    = %d\n",hplo);
		printf("Status Kepiting = %d\n",hpkep);
		printf("\n1. Berimakan lohan\n");
		printf("2. Berimakan kepiting\n");
		if(hplo<=0 || hplo>100 || hpkep<=0 || hpkep>100){
			printf("\n\tGAME OVER\nPELIHARAAN ANDA ADA YANG MATI\n");
			exit(EXIT_SUCCESS);
		}

	}
	return NULL;
}

void* kepiting(void *arr){

	while(1){
		sleep(20);
		hpkep-=10;
		system("clear");

		printf("Status Lohan    = %d\n",hplo);
		printf("Status Kepiting = %d\n",hpkep);
		printf("\n1. Berimakan lohan\n");
		printf("2. Berimakan kepiting\n");
		if(hplo<=0 || hplo>100 || hpkep<=0 || hpkep>100){
			printf("\n\tGAME OVER\nPELIHARAAN ANDA ADA YANG MATI\n");
			exit(EXIT_SUCCESS);
		}
	}

	return NULL;
}


int main(){
	system("clear");
	pthread_create(&(tid3), NULL, &menu, NULL);
	pthread_create(&(tid1), NULL, &lohan, NULL);
    pthread_create(&(tid2), NULL, &kepiting, NULL);
 
 	pthread_join(tid3, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}