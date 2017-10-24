#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid1, tid2;
int hplo=100, hpkep=100;


void* lohan(void *arg){
	
	printf("Status Lohan = %d/n",hplo);
	while(1){
		sleep(10);
		hplo-=15;
		printf("Status Lohan = %d/n",hplo);
	}
	return NULL;
}

void* kepiting(void *arr){


	return NULL;
}


int main(){
	pthread_create(&(tid1), NULL, &lohan, NULL);
    pthread_create(&(tid2), NULL, &kepiting, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
}