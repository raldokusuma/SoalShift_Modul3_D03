#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

int poin1,poin2;
int lub1[17],lub2[17];
char play1[50],play2[50];
pthread_t tid1,tid2,tid3;
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
			printf("Masukkan no lubang(1-16) =  ");
			if(ranj1==1){
				scanf("%d",&a);
				if(lub1[a]!=-1) lub1[a]=1;
			}
			else if(ranj1==2){
				scanf("%d %d",&a,&b);
				if(lub1[a]!=-1) lub1[a]=1;
				if(lub1[b]!=-1) lub1[b]=1;
			}
			else if(ranj1==3){
				scanf("%d %d %d",&a,&b,&c);
				if(lub1[a]!=-1) lub1[a]=1;
				if(lub1[b]!=-1) lub1[b]=1;
				if(lub1[c]!=-1) lub1[c]=1;
			}
			else if(ranj1==4){
				scanf("%d %d %d %d",&a,&b,&c,&d);
				if(lub1[a]!=-1) lub1[a]=1;
				if(lub1[b]!=-1) lub1[b]=1;
				if(lub1[c]!=-1) lub1[c]=1;
				if(lub1[d]!=-1) lub1[d]=1;
			}
			else printf("Ranjau minimal 1 maximal 4\n");
			sleep(1);
			system("clear");
			printf("%s Menebak 4 Lubang (1-16) = ", play2);
			scanf("%d %d %d %d",&d,&e,&f,&g);
			if(lub1[d]==1) {poin2+=1; lub1[d]= -1;}
			if(lub1[d]==0) poin1+=1;
			if(lub1[e]==1) {poin2+=1; lub1[e]= -1;}
			if(lub1[e]==0) poin1+=1;
			if(lub1[f]==1) {poin2+=1; lub1[f]= -1;}
			if(lub1[f]==0) poin1+=1;
			if(lub1[g]==1) {poin2+=1; lub1[g]= -1;}
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
			printf("Masukkan no lubang(1-16) =  ");
			if(ranj2==1){
				scanf("%d",&a);
				if(lub2[a]!=-1) lub2[a]=1;
			}
			else if(ranj2==2){
				scanf("%d %d",&a,&b);
				if(lub2[a]!=-1) lub2[a]=1;
				if(lub2[b]!=-1) lub2[b]=1;
			}
			else if(ranj1==3){
				scanf("%d %d %d",&a,&b,&c);
				if(lub2[a]!=-1) lub2[a]=1;
				if(lub2[b]!=-1) lub2[b]=1;
				if(lub2[c]!=-1) lub2[c]=1;
			}
			else if(ranj1==4){
				scanf("%d %d %d %d",&a,&b,&c,&d);
				if(lub2[a]!=-1) lub2[a]=1;
				if(lub2[b]!=-1) lub2[b]=1;
				if(lub2[c]!=-1) lub2[c]=1;
				if(lub2[d]!=-1) lub2[d]=1;
			}
			else printf("Ranjau minimal 1 maximal 4\n");
			sleep(1);
			system("clear");
			printf("%s Menebak 4 Lubang(1-16) = ", play1);
			scanf("%d %d %d %d",&d,&e,&f,&g);
			if(lub2[d]==1) {poin1+=1; lub2[d]=-1;}
			if(lub2[d]==0) poin2+=1;
			if(lub2[e]==1) {poin1+=1; lub2[e]=-1;}
			if(lub2[e]==0) poin2+=1;
			if(lub2[f]==1) {poin1+=1; lub2[f]=-1;}
			if(lub2[f]==0) poin2+=1;
			if(lub2[g]==1) {poin1+=1; lub2[g]=-1;}
			if(lub2[g]==0) poin2+=1;
		stat1=1;
		stat2=0;
		}
	}
}
}

void *check(void *cbc){
	int i, check;
	while(1){
		int flag1=0,flag2=0;
		for(i=1;i<17;i++){
			if (lub1[i]==1 || lub1[i]==-1) flag1+=1;
			if (lub2[i]==1 || lub2[i]==-1) flag2+=1;
			if(flag1>=16 && flag2 >= 16){
				sleep(0.8);
				system("clear");
				printf("Kedua Lubang telah Penuh Ranjau\n");
				printf("Skor %s = %d\n", play1,poin1);
				printf("Skor %s = %d\n", play2,poin2);
				sleep(2);
				exit(EXIT_SUCCESS);
			}
		}
		if(poin2>=10 || poin1>=10){
			printf("Game Berakhir\n");
			printf("Skor %s = %d\n", play1,poin1);
			printf("Skor %s = %d\n", play2,poin2);
			sleep(2);
			exit(EXIT_SUCCESS);
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
	pthread_create(&(tid3), NULL, &check, NULL);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    pthread_join(tid3, NULL);

}