#include <stdio.h>
#include <sys/types.h>
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

	write(pipefd[1], str1, strlen(str1)+1);
	read(pipefd[0], str2, 255);
	printf("%s\n", str2);
	return 0;
}