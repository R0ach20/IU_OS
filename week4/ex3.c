#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX 256

void execute(char* str){
	int f = fork();
	if(f==0){//if this is child

		// "/usr/bin/[str]""
		char cmd[MAX+9] = "/usr/bin/";
		for(int i=0; i<MAX && str[i] != '\n' && str[i] != '\0'; i++){
			cmd[i+9] = str[i];
		}

		//look in /usr/bin/
		int ret = execl(cmd, str, NULL);
		// look in /bin/
		if (ret == -1){
			ret = execl(cmd+4, str, NULL);
		}
		// look in current directory
		if (ret == -1){
			ret = execl(cmd+9, str, NULL);
		}
		// not found
		if(ret == -1){
			printf("command not found\n");
		}
	}
}

int main(){
	char str[MAX];
	printf("Only commands without args up to 256 symbols long\n");
	while(1){
		fgets(str, MAX, stdin);
		execute(str);
	}
	return 0;
}