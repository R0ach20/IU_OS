#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

int main(int argc, char const *argv[]){
	int fin_d;
	FILE* fout;
	if(argc == 3){
		fin_d = open(argv[1], O_RDONLY);
		fout = fopen(argv[2], "w");
	}else{
		fin_d = open("input.txt", O_RDONLY);
		fout = fopen("output.txt", "w");
	}

	//map file into memory
	struct stat st;
	fstat(fin_d, &st);
	size_t size = st.st_size;
	char* addr = mmap(NULL, size, PROT_READ, MAP_SHARED, fin_d, 0);
	char* inp = (char*) malloc(size);

	strcpy(inp, addr);//copy content


	//count number of nonempty lines
	int line_count = 0;
	char* line = strtok(inp,"\n");
	for(; line != NULL; line_count++,
		line = strtok(NULL, "\n"));



	strcpy(inp, addr);//restore content



	//save lines individually
	char *lines[line_count];
	lines[0] = strtok(inp,"\n");
	for(int i=1; i<line_count; i++)
		lines[i] = strtok(NULL, "\n");
	

	

	//count number of integers in first line
	int n = 1;
	for(int i=0; i<strlen(lines[0]); i++)
		if(lines[0][i] == ' ')
			n++;

	


	//read E from first line
	int E[n];
	sscanf(strtok(lines[0]," "), "%d", E+0);
	for(int i=1; i<n; i++)
		sscanf(strtok(NULL," "), "%d", E+i);
	


	//read A from second line
	int A[n];
	sscanf(strtok(lines[1]," "), "%d", A+0);
	for(int i=1; i<n; i++)
		sscanf(strtok(NULL," "), "%d", A+i);
	


	//2 lines are E and A
	//=> (line count - 2) lines are for C and R
	//=> m = |C| = |R| = (line_count-2)/2
	int m = (line_count - 2)/2;


	//read C matrix
	int C[m][n];
	for(int i=0; i<m; i++){
		sscanf(strtok(lines[2+i]," "), "%d", &C[i][0]);
		for(int j=1; j<n; j++){
			sscanf(strtok(NULL," "), "%d", &C[i][j]);
		}
	}

	//read R matrix
	int R[m][n];
	for(int i=0; i<m; i++){
		sscanf(strtok(lines[2+i+m]," "), "%d", &R[i][0]);
		for(int j=1; j<n; j++){
			sscanf(strtok(NULL," "), "%d", &R[i][j]);
		}
	}

	//unmap and close input file
	munmap(addr, size);
	close(fin_d);

	/////////////////////
	//Reading completed//
	/////////////////////


	char locked = FALSE;
	char completed[m];
	for(int i=0; i<m; i++){
		completed[i] = FALSE;
	}


	char some_comleted = TRUE;//flag to detect if at least one procces could be completed and removed from C and R
	//execute processes while at least one completes each cycle
	while(some_comleted){
		some_comleted = FALSE;

		for(int i=0; i<m; i++){
			char could_complete = TRUE;

			for(int j=0; j<n && !completed[i]; j++){
				if(R[i][j] > A[j]){//If procces lacks at least one resource to complete
					could_complete = FALSE;
				}
			}

			//if has all needed resourses and was not copleted before
			if(could_complete && !completed[i]){
				some_comleted = TRUE;
				completed[i] = TRUE;//mark as completed
				//free used resources
				for(int j=0; j<n; j++){
					A[j] += C[i][j];
				}
			}
		}
	}

	//no more processes could be completed
	for(int i=0; i<m; i++){
		if(!completed[i]){
			locked = TRUE;
		}
	}

	if(locked){
		fprintf(fout, "Deadlock detected\nDeadlocked processes:\n");
		for(int i=0; i<m; i++){
			if(!completed[i]){
				fprintf(fout, "%d\n", i+1);//numeration from 1
			}
		}
	}else{
		fprintf(fout, "No deadlock detected\n");
	}
	return 0;
}