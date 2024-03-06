#include<stdlib.h>
#include<stdio.h>
#include<unistd.h> // for fork - UNIX
#include<pthread.h>
#include<time.h>

int main(int argc, char* argv[]){
	int id = fork();
//	fork();  // try to have multiple forks and see how it acts
//	fork();
	printf("Hello! from Process ID : %d\n", id); // ID in the child process will be zero
	return 0;
}
