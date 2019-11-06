#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[]){
	if(argc < 2){
		printf("%s file1 -a file2\n", argv[0]);
		return -1;
	}

	int n = argc - 1;
	for(int i=1; i<argc-1; i++){
		if (argv[i][0] == '-'){
			if(strcmp(argv[i], "-a") != 0 || argv[i+1][0] == '-'){
				printf("%s file1 -a file2\n", argv[0]);
				return -1;
			}
			n--;
		}
	}

	int fd[n];
	n = 0;
	for(int i=1; i<argc; i++, n++){
		if(strcmp(argv[i], "-a") == 0){
			fd[n] = open(argv[i+1], O_WRONLY|O_APPEND|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);
			i++;
		}else{
			fd[n] = open(argv[i], O_WRONLY|O_CREAT, S_IRWXU|S_IRWXG|S_IRWXO);
		}
	}

	char c;

	while(read(fileno(stdin), &c, 1) == 1){
		printf("%c", c);

		for(int i=0; i<n; i++){
			write(fd[i], &c, 1);
		}
	}
	return 0;
}