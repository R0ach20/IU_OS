#include <stdio.h>

void bubble_sort(int *a, int n){
	int sorted = 0;
	while(!sorted){
		sorted = 1;
		for(int i=0; i<n-1; i++){
			if(a[i] > a[i+1]){
				int temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				sorted = 0;
			}
		}
	}
}

int main(int argc, char const *argv[]){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	bubble_sort(a, n);

	for(int i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
