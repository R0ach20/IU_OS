#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>


int main(int argc, char const *argv[]){
	struct stat st;
	
	int fd = open("ex1.txt", O_RDWR);
	fstat(fd, &st);
	off_t size = st.st_size;
	char* addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	
	strcpy(addr, "This is a nice day");

	ftruncate(fd, strlen(addr));
	close(fd);

	return 0;
}