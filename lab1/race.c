#include<stdlib.h>
#include<stdio.h>
//#include<conio.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

int x =0;

void* routine(void *input){
	for(int i=0;i <100000; i++){ // large number results in race
		x++;
	}
}


int main(int argc, char* argv[]){ // with exception / error handling

	printf("Hello! from main\n");
	pthread_t t1,t2;
	if(pthread_create(&t1,NULL,&routine,"1") !=0){
		return 1;
	}
	if(pthread_create(&t2,NULL,&routine,"2") !=0){
		return 2;
	}
	if(pthread_join(t1,NULL) !=0){
		return 3;
	}
	if(pthread_join(t2,NULL) !=0){
		return 4;
	}
	printf("# of mails : %d\n",x);

	return 0;
}



