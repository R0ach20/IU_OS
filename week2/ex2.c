#include <stdio.h>


int main(int argc, char const *argv[]){
	char str[512];
	fgets(str, 512, stdin);

	int i = 0;
	while(str[i] != '\0'){
		i++;
	}
	i--;


	while(i >= 0){
		putchar(str[i]);
		i--;
	}
	printf("\n");
	return 0;
}