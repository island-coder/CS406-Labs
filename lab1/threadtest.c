#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<time.h>

int x =0;

void* routine(void *input){
	printf("Greetings from the thread %s\n",(char *)input);
	sleep(2);
	printf("Ending the thread %s\n",(char *)input);
}


int main(int argc, char* argv[]){

	printf("Hello! from main\n");

       	pthread_t t1,t2; //
 
	if(pthread_create(&t1,NULL,&routine,"1") !=0){ // with error handling
		return 1;
	}
	if(pthread_create(&t2,NULL,&routine,"2") !=0){ // with error handling 
		return 2;
	}
	pthread_join(t1,NULL); //joining the the thread with main thread
	pthread_join(t2,NULL);
	return 0;
}
