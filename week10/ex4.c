#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

typedef struct {
	ino_t inode;
	unsigned int count;
}inode_counter;

int main(int argc, char const *argv[]){
	DIR* dirp = opendir("tmp");
	if(dirp == NULL){
		printf("Could not open directory ./tmp/\n");
		return -1;
	}

	struct dirent dr[1024];
	int count = 0;;
	inode_counter inums[1024];
	for(int i=0; i<1024; i++){
		inums[i].inode = 0;
		inums[i].count = 1;
	}
	int k = 0;
	struct dirent* drp;
	for(int i=0; (drp=readdir(dirp)) != NULL && i<1024; i++, count++){
		dr[i] = *drp;
		int f = -1;
		//count occurences ofeach inode number
		for(int j=0; j<k && f == -1; j++){
			if(inums[j].inode == dr[i].d_ino){
				f = j;
				inums[f].count++;
			}
		}
		//if not found add new
		if(f == -1){
			inums[k].inode = dr[i].d_ino;
			k++;
		}
	}

	// for(int j=0; j<count; j++){
	// 	printf("%ld %s\n",dr[j].d_ino, dr[j].d_name );
	// }
	// for(int i=0; i<k; i++){
	// 	printf("%ld %d\n", inums[i].inode, inums[i].count);
	// }

	FILE* fout = fopen("ex4.txt", "w");

	for(int i=0; i<k; i++){
		if(inums[i].count >= 2){
			fprintf(fout, "%ld ", inums[i].inode);
			for(int j=0; j<count; j++){
				if(dr[j].d_ino == inums[i].inode){
					fprintf(fout, "%s ", dr[j].d_name);
				}
			}
			fprintf(fout, "\n");
		}
	}
	
	fclose(fout);
	return 0;
}

//Output:
//1705834 file1 link1 