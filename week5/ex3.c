#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define MAX 10
int count = 0;
int producerState = 1;//0 = sleep
int consumerState = 1;//1 = awake
unsigned int printCounter = 0;


void produce(){
	while(1){
		while(producerState == 0){
			;
		}
		if(count == MAX){
			producerState = 0;
			//printf("PSleep\n");
		}else{
			//printf("PAwake\n");
			count++;
			consumerState = 1;
		}
		
	}
}

void consume(){
	while(1){
		while(consumerState == 0){
			;
		}
		if (count == 0){
			consumerState = 0;
			producerState = 1;
			//printf("CSleep\n");
		}else{
			//printf("CAwake\n");
			count--;
		}
	}
}



int main(int argc, char const *argv[]){

	pthread_t consumer;
	pthread_t producer;

	FILE* file = fopen("ex3.out", "w");
	fprintf(file, "%ld\n", time(NULL));
	
	pthread_create(&producer, NULL, produce, NULL);
	pthread_create(&consumer, NULL, consume, NULL);
	
	while(1){
		fprintf(file, ":producerState=%d consumerState=%d\n", producerState, consumerState);
		sleep(0.1);
	}
	fprintf(file, ":producerState=%d consumerState=%d\n", producerState, consumerState);
	fprintf(file, "------BOTH THREADS ARE SLEEPING------\n");
	fprintf(file, "%ld\n", time(NULL));

	return 0;
}
