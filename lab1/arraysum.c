
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main()
{

	int fd[2];
	if (pipe(fd) < 0)
	{
		printf("error in pipe initialization\n");
		return 1;
	}
	printf("pipe created sucessfully\n");

	//int arr[] = {5, 10, 6, 9, 3, 1, 8, 5, 8, 1, 1, 7, 1, 8, 0, 0, 4, 8, 2, 1, 9, 1, 0, 5, 7, 6, 2, 2, 7, 10, 6, 0, 2, 9, 3, 10, 1, 8, 9, 0, 7, 1, 6, 10, 7, 9, 4, 2, 0, 3, 9, 1, 1, 8, 9, 6, 6, 0, 6, 10, 0, 4, 8, 8, 9, 10, 9, 0, 9, 8, 3, 5, 0, 3, 0, 10, 5, 4, 9, 7, 3, 0, 8, 2, 5, 6, 9, 2, 2, 4, 4, 8, 0, 7, 0, 7, 10, 6, 8, 9};
	int arr[] = {5};
	int len = sizeof(arr) / sizeof(arr[0]);
	printf("size : %d \n", len);
	int child_sum = 0;

	int pid = fork();

	if (pid < 0)
	{
		printf("error in forking\n");
	}
	if (pid == 0)
	{
		child_sum = 0;
		printf("child process running ...\n");
		for (int i = 0; i < len / 2; i++)
		{
			printf("summing in child ...\n");
			child_sum += arr[i];
		}
		//sleep(5);
		close(fd[0]);
	
		if (write(fd[1], &child_sum, sizeof(int)) < 0)
		{
			printf("error in writing\n");
			return -1;
		}
		sleep(5);
		close(fd[1]);
		printf("child sum : %d\n", child_sum);
	}
	else
	{
		printf("parent process running ...\n");

		int parent_sum = 0, total_sum = 0;
		for (int i = len / 2; i < len; i++)
		{
			printf("summing in parent ...\n");
			parent_sum += arr[i];
		}
		wait(NULL); // waits until child completes 
		close(fd[1]);

		if (read(fd[0], &child_sum, sizeof(int)) < 0)
		{
			printf("error in reading\n");
			return -1;
		}
		close(fd[0]);

		printf("child sum read by parent: %d\n", child_sum);

		total_sum = child_sum + parent_sum;
		printf("total sum: %d\n", total_sum);
	}
	return 0;
}
