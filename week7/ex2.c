#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]){
	int n=0;
	printf("Enter n: ");
	scanf("%d", &n);
	int *a = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		a[i] = i;
	}

	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	free(a);
	return 0;
}