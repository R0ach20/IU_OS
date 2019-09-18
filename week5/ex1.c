#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>



void th_funct_nonsync(int n){
	printf("Thread No:%d\n", n);
}


int main(int argc, char const *argv[]){
	if(argc == 1){
		printf("Pass N as first arg\n");
		return 0;
	}
	int n;
	sscanf(argv[1], "%d", &n);

	pthread_t threads[n];

	//Threads execute in unpredictable order
	/*
	for(int i=0; i<n; i++){
		pthread_create(&threads[i], NULL, th_funct_nonsync, i);
	}

	for(int i=0; i<n; i++){
		pthread_join(threads[i], NULL);
	}
	*/

	//Program wait for thread to exit before executing next,
	//Every time print in order
	for(int i=0; i<n; i++){
		pthread_create(&threads[i], NULL, th_funct_nonsync, i);
		pthread_join(threads[i], NULL);
	}


	return 0;
}