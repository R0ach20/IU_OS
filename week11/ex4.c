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
	int new_fd = open("ex1.memcpy.txt", O_RDWR|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);

	fstat(fd, &st);
	off_t size = st.st_size;

	char* addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	
	ftruncate(new_fd, strlen(addr));//resize new file

	char* new_addr = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, new_fd, 0);


	memcpy(new_addr, addr, size);

	
	close(fd);
	close(new_fd);
	return 0;
}