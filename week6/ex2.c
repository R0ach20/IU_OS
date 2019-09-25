#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){
	int pipefd[2];
	char str1[] = "inblserf jdkper";
	char str2[255];
	if(pipe(pipefd)==-1){
		return -1;
	}

	pid_t f = fork();

	if(f > 0){
		close(pipefd[0]);
		write(pipefd[1], str1, strlen(str1)+1);
		wait(NULL);

	}else if(f==0){
		close(pipefd[1]);
		read(pipefd[0], str2, 255);
		printf("%s\n", str2);
		
	}else{//Error
		return -1;
	}
	return 0;
}