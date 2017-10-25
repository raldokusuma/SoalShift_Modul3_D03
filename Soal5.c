#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[100];
int status=0;
int j=1;
char *kata[100];
char seek[1000];
int stat1=0;
void *cari(void * azz){
	FILE *f;
	char c[512];	
	int jml=0;
	f = fopen ("./Novel.txt", "r");
	while(fgets(c,512,f) != NULL){
		if(strcmp(c,kata[j]) != 1){
			jml++;
		}
	}

	printf("%s : %d\n",kata[j],jml);
	j++;

	status=1;
}


int main(int argc , char **argv){
	int a;
	int i=1;
	int k;
	int n=sizeof(argv)/sizeof(int);
	while(argv[i]!=NULL){	
		kata[i]=argv[i];
		i++;
	}

	for(k=1;k<i;k++){
	pthread_create(&(tid[k]), NULL, &cari, NULL);
	while(status==0){}
	}
		for(k=1;k<i;k++){
	pthread_join(tid[k], NULL);
	
	}
}