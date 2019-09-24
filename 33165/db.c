#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>  
#include <stdlib.h>   
	
int main() {
	int file, choice = 1;
	size_t n;
	char filename[20], *bufferwrite, *bufferread;//, O_RDONLY, O_CREATE, O_APPEND, O_WRONLY;
	
	printf("Enter file name : ");
	scanf("%s", filename);
	printf("Create employee database");
	
	while(choice > 0 && choice < 6) {
		printf("\nSelect operation : \n1. Create file\n2. Write to file\n3. Read from file\n4.Update\n5.Search\n6.Exit");
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				file = open(filename, O_CREAT);
				close(file);
				break;
			
			case 2:
				file = open(filename, O_CREAT | O_WRONLY);
				printf("Enter data to write to file : ");
				getline(&bufferwrite, &n, stdin);//scanf("%s", buffer);
				write(file, (char *)bufferwrite, strlen(bufferwrite));
				close(file);
				break;
				
			case 3:
				file = open(filename, O_APPEND)
				
			default:
				choice = -1;
		}	
	}
	
	return 0;
}
