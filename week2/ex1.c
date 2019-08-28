#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(int argc, char const *argv[]){
	int i;
	float f;
	double d;

	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;
	
	printf("int %d size %ld\n\n", i, sizeof(i));
	printf("float %f size %ld\n\n", f, sizeof(f));
	printf("double %lf size %ld\n\n", d, sizeof(d));
	return 0;
}