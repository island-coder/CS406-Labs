#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/types.h>

int x=2;


int main(int argc, char* argv[]){ 

	printf("staring of main\n");

//	pid_t pid= getpid(); //  even int would work : int pid= getpid(); 
	int pid= fork();   //actually forks into two processes(Parent and child, wont just create another!!!)

	printf("PID : %d\n",pid);  //pid uniquely identifies process , if forked,child will have pid of 0
	if (pid == -1){		//returns -1 if there was an error
		return 1;
	}
	if (pid == 0){		
		x++; // childs x increases.. (child has seperate copy of variable)
	}

	sleep(2);
	printf("%d Process value of x:%d\n",pid,x);

	if(pid !=0 ){
		wait(NULL);
	}


        return 0;
}


