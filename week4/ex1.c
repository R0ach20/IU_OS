#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
	int n = 28200;
	pid_t f = fork();
	pid_t pid = getpid();
	if(f == 0){
		printf("Hello from child %d\n", pid - n);
	}else{
		printf("Hello from parent %d\n", pid - n);
	}
	return 0;
}

/*
./ex1.bash

Run 1
Hello from parent 222
Hello from child 223
Run 2
Hello from parent 224
Hello from child 225
Run 3
Hello from parent 226
Hello from child 227
Run 4
Hello from parent 228
Hello from child 229
Run 5
Hello from parent 230
Hello from child 231
Run 6
Hello from parent 232
Hello from child 233
Run 7
Hello from parent 234
Hello from child 235
Run 8
Hello from parent 236
Hello from child 237
Run 9
Hello from parent 238
Hello from child 239
Run 10
Hello from parent 240
Hello from child 241



Each time a new process created it get a PID 
from some system variable, which is being incremented each time 
it's value is used for a PID.
*/