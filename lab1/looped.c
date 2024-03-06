#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

int x =0;
/*int lock = 0; // example lock*/
pthread_mutex_t mutex;

void* routine(){
	for(int i=0;i <100000; i++){ // large number results in race
		pthread_mutex_lock(&mutex);
		x++;
		pthread_mutex_unlock(&mutex);
	}
}


int main(int argc, char* argv[]){ // with exception / error handling

	pthread_t th[4];
	int i;
	pthread_mutex_init(&mutex,NULL);
	for(i=0; i<4; i++){ // this gives the concurrence
		if(pthread_create(&th[i],NULL,&routine,NULL) !=0){
			perror("failed to create the thread");
			return 1;
		}
		printf("Thread %d has started \n",i);
	}

	for (i=0;i<4;i++){
		if(pthread_join(th[i], NULL) != 0){
			printf("error i =%d",i);
			return 2;
		}
		printf("Thread %d has finished \n",i);
	}

	pthread_mutex_destroy(&mutex);
	printf("X : %d\n",x);

	return 0;
}



