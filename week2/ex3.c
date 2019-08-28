#include <stdio.h>


void right_side_up_trinagle(int n){//a.out n 0
	for(int i = 0; i<n; i++){
		//left half
		for(int j=0; j < n-i; j++){
			putchar(' ');
		}
		for(int j=0; j < i; j++){
			putchar('*');
		}
		//left half

		putchar('*');//middle star

		//right half
		for(int j=0; j < i; j++){
			putchar('*');
		}
		for(int j=0; j < n-i; j++){
			putchar(' ');
		}
		//right half

		putchar('\n');
	}
}

void square(int n){//a.out n 1
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			putchar('*');
		}
		putchar('\n');
	}
}


int main(int argc, char const *argv[]){
	if(argc < 2){
		return 1;
	}

	int n;
	sscanf(argv[1], "%d", &n);
	int width = 2*n - 1;

	if(argv == 2){
		right_side_up_trinagle(n);
	}else{
		int figure;
		sscanf(argc[2], "%d", &figure);
		swithc(figure){
			0:
				right_side_up_trinagle(n);
				break;
			1:
				square(n);
				break;
		}
	}
	return 0;
}