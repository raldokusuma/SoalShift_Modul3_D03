#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int poin1,poin2;
int lub1[17],lub2[17];
char play1[50],play2[50];
pthread_t tid1,tid2;
int ranj1,ranj2;
int a,b,c,d;
int d,e,f,g;
int stat1=1,stat2=0;

void * first(void *aww){
	int choice;
	while(1){
	while(stat1==1){
		system("clear");
		printf("1. Cek Poin \n");
		printf("2. Mulai Turn \n");
		scanf("%d",&choice);
		if(choice == 1){
			system("clear");
			printf("POIN STATUS\n\n");
			printf("Poin %s = %d\n",play1,poin1);
			printf("Poin %s = %d\n",play2,poin2);
			sleep(3);
		}
		else if(choice == 2){
			system("clear");
			printf("%s Masukkan Jumlah Ranjau(Min 1, Max 4) = ",play1);
			scanf("%d",&ranj1);
			printf("Masukkan no lubang =  ");
			if(ranj1==1){
				scanf("%d",&a);
				lub1[a]=1;
			}
			else if(ranj1==2){
				scanf("%d %d",&a,&b);
				lub1[a]=1;
				lub1[b]=1;
			}
			else if(ranj1==3){
				scanf("%d %d %d",&a,&b,&c);
				lub1[a]=1;
				lub1[b]=1;
				lub1[c]=1;
			}
			else if(ranj1==4){
				scanf("%d %d %d %d",&a,&b,&c,&d);
				lub1[a]=1;
				lub1[b]=1;
				lub1[c]=1;
				lub1[d]=1;
			}
			else printf("Ranjau minimal 1 maximal 4\n");
			system("clear");
			printf("%s Menebak di Lubang = ", play2);
			scanf("%d %d %d %d",&d,&e,&f,&g);
			if(lub1[d]==1) poin2+=1;
			if(lub1[d]==0) poin1+=1;
			if(lub1[e]==1) poin2+=1;
			if(lub1[e]==0) poin1+=1;
			if(lub1[f]==1) poin2+=1;
			if(lub1[f]==0) poin1+=1;
			if(lub1[g]==1) poin2+=1;
			if(lub1[g]==0) poin1+=1;
			stat1=0;
			stat2=1;
		}

	}
}

}

void * sec(void *arr){
	int choice;
	while(1){
	while(stat2==1){
		system("clear");
		printf("1. Cek Poin \n");
		printf("2. Mulai Turn \n");
		scanf("%d",&choice);
		if(choice == 1){
			system("clear");
			printf("POIN STATUS\n\n");
			printf("Poin %s = %d\n",play1,poin1);
			printf("Poin %s = %d\n",play2,poin2);
			sleep(3);
		}
		else if(choice == 2){
			system("clear");
			printf("%s Masukkan Jumlah Ranjau(Min 1, Max 4) = ",play2);
			scanf("%d",&ranj2);
			printf("Masukkan no lubang =  ");
			if(ranj2==1){
				scanf("%d",&a);
				lub2[a]=1;
			}
			else if(ranj2==2){
				scanf("%d %d",&a,&b);
				lub2[a]=1;
				lub2[b]=1;
			}
			else if(ranj1==3){
				scanf("%d %d %d",&a,&b,&c);
				lub2[a]=1;
				lub2[b]=1;
				lub2[c]=1;
			}
			else if(ranj1==4){
				scanf("%d %d %d %d",&a,&b,&c,&d);
				lub2[a]=1;
				lub2[b]=1;
				lub2[c]=1;
				lub2[d]=1;
			}
			else printf("Ranjau minimal 1 maximal 4\n");
			system("clear");
			printf("%s Menebak di Lubang = ", play1);
			scanf("%d %d %d %d",&d,&e,&f,&g);
			if(lub2[d]==1) poin1+=1;
			if(lub2[d]==0) poin2+=1;
			if(lub2[e]==1) poin1+=1;
			if(lub2[e]==0) poin2+=1;
			if(lub2[f]==1) poin1+=1;
			if(lub2[f]==0) poin2+=1;
			if(lub2[g]==1) poin1+=1;
			if(lub2[g]==0) poin2+=1;
		stat1=1;
		stat2=0;
		}
	}
}
}

int main(){
	system("clear");
	printf("Nama Player 1 : ");
	scanf("%s",play1);
	printf("Nama PLayer 2 : ");
	scanf("%s",play2);

	pthread_create(&(tid1), NULL, &first, NULL);
	pthread_create(&(tid2), NULL, &sec, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

}