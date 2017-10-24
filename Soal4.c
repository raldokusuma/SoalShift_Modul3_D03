#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid1;
int arr[100];

int main(int argc , char **argv){
	int a;
	int i=1;
	while(argv[i]!=NULL){
		arr[i]=atoi(argv[i]);
		i++;
	}
	printf ("%d\n",arr[1]);

}