#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char const *argv[]){
	pid_t f = fork();
	if(f > 0){
		sleep(10);
		char* command[50];
		sprintf(command, "kill %d", f);
		system(command);
	}else if(f == 0){
		while(1){
			printf("I'm alive\n");
			sleep(1);
		}
	}else{//Error
		return -1;
	}
	return 0;
}