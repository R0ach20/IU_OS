#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char const *argv[]){
	pid_t c1;
	pid_t c2;
	char b[255];//buffer for pipe
	int pipefd[2];

	if(pipe(pipefd)==-1){
		return -1;
	}
	
	c1 = fork();
	if(c1 > 0){
		printf("forked child 1 : %d\n", c1);
		c2 = fork();

		if(c2 > 0){//Parent
			printf("forked child 2 : %d\n", c2);

			close(pipefd[0]);
			sprintf(b, "%d", c2);
			write(pipefd[1], b, strlen(b)+1);
			close(pipefd[1]);

			printf("sent [%s] to pipe\n", b);

			printf("waiting for state change in child 2\n");
			int *s;
			waitpid(c2, &s,0);
			printf("C2 state changed\n");
		}else if(c2 == 0){//child 2
			printf("Child 2\n");
			while(1){
				;
			}
		}else{//Error
			return -1;
		}
		
		
	}else if(c1 == 0){//child 1
		close(pipefd[1]);
		read(pipefd[0], b, 255);
		close(pipefd[0]);
		printf("recieved [%s] from pipe\n", b);

		sscanf(b, "%d", &c2);
		printf("child 2 PID = %d\n", c2);
		printf("sleeping for 2 seconds\n");
		sleep(2);

		printf("Sending sigstop to child 2\n");
		char com[255];
		sprintf(com, "kill %d", c2);
		system(com);

	}else{//Error
		return -1;
	}
	
	return 0;
}