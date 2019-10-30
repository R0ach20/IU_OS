#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char const *argv[]){
	
	char* buf = (char*)malloc(5*sizeof(char));
	setvbuf(stdout, buf, _IOLBF, 5);

	printf("H");
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1);

	printf("\n");

	return 0;
}