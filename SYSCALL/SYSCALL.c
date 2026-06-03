#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (){


	pid_t pid;
	
	pid = fork();

	
	if (pid < 0){
		
		printf("Fork Failed !\n");

		return 1;

	}
	else if (pid  == 0){

		printf("CHILD - PID :%d ,Parent PID: %d\n",getpid() ,getppid());

	}
	else {

		printf("PARENT - PID: %d ,child PID: %d \n" ,getpid() ,pid);

		wait(NULL);

	}
	return 0;


}
