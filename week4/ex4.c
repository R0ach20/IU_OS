#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256

void execute(char* str){

	int f = fork();
	if(f==0){//if this is child
		//split str by spaces and count arguments
		int argc = 1;
		for(int i=0; i<MAX && str[i] != '\0'; i++){
			if(str[i] == ' ' || str[i]=='\n'){
				if(str[i]==' '){
					argc++;
				}
				str[i]='\0';
			}
		}

		//array of arguments to pass
		char *argv[argc+1];
		argv[argc] = NULL;//last element have to be NULL

		//writing arguments to argv
		for(int i=0, j=0; i<argc; i++){
			argv[i] = str+j;
			//skiping to next 
			while(str[j] != '\0'){
				j++;
			}
			j++;
		}

		//path and 0-th argument
		char cmd[MAX+9] = "/usr/bin/";
		strcat(cmd, argv[0]);
		argv[0] = cmd;//0-yh argument is the path

		//look in /usr/bin/
		int ret = execv(cmd, argv);
		// look in /bin/
		if (ret == -1){
			argv[0] = cmd+4;
			ret = execv(cmd+4, argv);
		}
		// look in current directory
		if (ret == -1){
			argv[0] = cmd+9;
			ret = execv(cmd+9, argv);
		}
		// not found
		if(ret == -1){
			printf("command not found\n");
		}
	}
}

int main(int argc, char const *argv[]){
	char str[MAX];
	printf("Only commands up to 256 symbols long\n");
	while(1){
		fgets(str, MAX, stdin);
		execute(str);
			
	}
	return 0;
}