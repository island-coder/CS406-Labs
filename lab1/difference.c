#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//#include<windows.h> // for windows for pthread.h
#include <sys/wait.h>
#include <sys/types.h>

int x=2;

void* t_test1(){
	x++;
	sleep(2); // sleep to allow the other threads to execute
	printf("Tread 1 : value of x is : %d\n",x);
}

void* t_test2(){
        x++;
        sleep(2);
        printf("Thread 2 : value of x is : %d\n",x);
}



int main(int argc, char* argv[]){ // with exception / error han>
/*process block
	printf("staring of main\n");
	int pid= fork();
	int x=2;
	printf("PID : %d\n",pid);
	if (pid == -1){
		return 1;
	}
	if (pid == 0){
		x++;
	}
	sleep(2);
	printf("Process value of x:%d\n",x);

	if(pid !=0 ){
		wait(NULL);
	}
end of process block*/
/* threads block*/
        printf("starting the threads\n");
        pthread_t t1,t2;

        if(pthread_create(&t1,NULL,&t_test1,NULL) !=0){
                return 1;
        }
        if(pthread_create(&t2,NULL,&t_test2,NULL) !=0){
                return 2;
        }
        if(pthread_join(t1,NULL) !=0){
                return 3;
        }
        if(pthread_join(t2,NULL) !=0){
                return 4;
        }
/*end of threads block*/
        return 0;
}


