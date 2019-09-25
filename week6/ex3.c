#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int sigINT(int sigsum){
	printf("sigInt intercepted\n");
	return 0;
}

int main(int argc, char const *argv[]){
	struct sigaction act;

	act.sa_handler = sigINT;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, NULL);
	while(1){
		;
	}
	return 0;
}