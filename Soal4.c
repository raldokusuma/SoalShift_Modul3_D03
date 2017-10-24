#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[100];
int arr[100];
int status=0;
int j=1;

void *hitung(void * azz){
	int fact=1;
	int c;
	for (c = 1; c <= arr[j]; c++) fact = fact * c;
	printf("Hasil %d! = %d\n", arr[j],fact);
	j++;
	status=1;
}


int main(int argc , char **argv){
	int a;
	int i=1;
	int k;
	while(argv[i]!=NULL){
		
		arr[i]=atoi(argv[i]);
		i++;
	}
	for(k=1;k<i;k++){
	pthread_create(&(tid[k]), NULL, &hitung, NULL);
	while(status==0){}
	}
		for(k=1;k<i;k++){
	pthread_join(tid[k], NULL);
	
	}
}