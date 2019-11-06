#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char const *argv[]){
	int r_d = open("/dev/random", O_RDONLY);
	if( r_d < 0){
		return -1;
	}

	FILE* fout = fopen("ex1.txt", "w");
	char data[21];
	if(read(r_d, data, 20) < 0){
		return -1;
	}
	data[20] = '\0';
	fprintf(fout, "%s", data);
	return 0;
}