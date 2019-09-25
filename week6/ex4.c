#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int sigUSR1handler(int sigsum){
	printf("sigUSR1 acquired\n");
	return 0;
}

int sigKILLhandler(int sigsum){
	printf("sigKILL acquired\n");
	return 0;
}

int sigSTOPhandler(int sigsum){
	printf("sigSTOP acquired\n");
	return 0;
}

int main(int argc, char const *argv[]){
	struct sigaction actUSR1, actKILL, actSTOP;

	actUSR1.sa_handler = sigUSR1handler;
	sigemptyset(&actUSR1.sa_mask);
	actUSR1.sa_flags = 0;
	sigaction(SIGUSR1, &actUSR1, NULL);

	actKILL.sa_handler = sigKILLhandler;
	sigemptyset(&actKILL.sa_mask);
	actKILL.sa_flags = 0;
	sigaction(SIGKILL, &actKILL, NULL);

	actSTOP.sa_handler = sigSTOPhandler;
	sigemptyset(&actSTOP.sa_mask);
	actSTOP.sa_flags = 0;
	sigaction(SIGSTOP, &actSTOP, NULL);
	while(1){
		;
	}
	return 0;
}

//kill -s SIGUSR1 sends only SIGUSR1
//thus output is sigUSR1 acquired