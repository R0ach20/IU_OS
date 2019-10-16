#include <stdio.h>
#include <stdlib.h>



//a.out 10 "Lab 09 input.txt" 
//hit/miss: 11/989 = 0.011122

//a.out 50 "Lab 09 input.txt" 
//hit/miss: 51/949 = 0.053741


//a.out 100 "Lab 09 input.txt" 
//hit/miss: 93/907 = 0.102536


typedef struct{
	unsigned int frame_number;
	unsigned char age;
}frame;


// ./a.out 10 "Lab 09 input.txt"
int main(int argc, char const *argv[]){
	if(argc < 2){
		printf("./a.out N \"Lab 09 input.txt\"\n");
		return -1;
	}

	int n=1;
	sscanf(argv[1], "%d", &n);
	FILE* inp;
	char* file_name;

	if(argc == 3){
		file_name = argv[2];
	}else{
		file_name = (char*)calloc(100, sizeof(char));
		file_name  = "Lab 09 input.txt\0";
	}

	printf("File:\"%s\"\npage frames:%d\n\n", file_name, n);
	inp = fopen(file_name, "r");

	if(inp == NULL){
		printf("File not found\n");
		return -1;
	}

	unsigned char hit = 0;
	int to_be_removed;
	unsigned int hit_counter = 0, miss_counter = 0;
	frame* table = (frame*) calloc(n, sizeof(frame));
	for(int i=0; i<n; i++){
		table[i].frame_number = 0;
		table[i].age = 0;
	}

	int page;
	fscanf(inp, "%d", &page);
	while(!feof(inp)){
		
		printf("Page %d ", page);
		hit = 0;
		to_be_removed = 0;
		for(int i=0; i<n; i++){
			table[i].age = table[i].age>>1;
			
			if(table[i].frame_number == page){
				hit = 1;
				table[i].age = table[i].age|0x80;
				printf("hit at page %d\n", i);
			}


			//frame_number == 0 --empty space
			if(table[i].frame_number == 0){
				to_be_removed = i;
			}else{
				if(table[i].age < table[to_be_removed].age && table[to_be_removed].frame_number != 0){
					to_be_removed = i;
				}
			}
		}
		if(!hit){
			table[to_be_removed].frame_number = page;
			table[to_be_removed].age = 0x80;
			printf("miss page %d replaced\n", to_be_removed);
		}

		hit_counter += hit;
		miss_counter += (1-hit);
		fscanf(inp, "%d", &page);
	}

	printf("hit/miss: %d/%d = %f\n", hit_counter, miss_counter, 1.0f*hit_counter/miss_counter);

	fclose(inp);
	return 0;
}