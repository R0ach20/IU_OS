#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

struct rusage rusageS;

int main(int argc, char const *argv[]){
	char *a[10];
	for(int i=0; i<10; i++){
		a[i] = (char*)malloc(sizeof(char) * 10485760);//10485760b = 10 Mb
		memset(a[i], 0, 10485760*sizeof(char));
		getrusage(RUSAGE_SELF, &rusageS);
		printf("\t%d:\nMax resident set size: %ld\n\n", i, rusageS.ru_maxrss);
		sleep(1);
	}
	return 0;
}