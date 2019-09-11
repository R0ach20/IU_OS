#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
	for(int i=0; i<5; i++){
		fork();
	}
	sleep(5);
	return 0;
}

/*
Process created by fork is at the same stage of execution as it's parent

each time fork is executed number of processes is doubled
after first fork: 2*a.out in all of which i=1
after second: 4*a.out, i=2
after 3-rd: 8*a.out, i=3
making it 2^n processes


3: 2^3=8
a.out─┬─a.out─┬─a.out───a.out
      │       └─a.out
      ├─a.out───a.out
      └─a.out

5:2^5 = 32
a.out─┬─a.out─┬─a.out─┬─a.out─┬─a.+
      │       │       │       └─a.+
      │       │       ├─a.out───a.+
      │       │       └─a.out
      │       ├─a.out─┬─a.out───a.+
      │       │       └─a.out
      │       ├─a.out───a.out
      │       └─a.out
      ├─a.out─┬─a.out─┬─a.out───a.+
      │       │       └─a.out
      │       ├─a.out───a.out
      │       └─a.out
      ├─a.out─┬─a.out───a.out
      │       └─a.out
      ├─a.out───a.out
      └─a.out

*/