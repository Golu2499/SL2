#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{

    int file;
    
    char *Fifo = "/temp/Fifo";
    char *Fifo1 = "/temp/Fifo1";
    int fd;
    

    int i;
    int w=0, l=0, c=0 ; 
    
    mkfifo(Fifo,0000);
    
    char array1[100];
    
    while(1)
    {
         file = open(Fifo,  O_WRONLY);
         //accessing the fifo
         printf("Enter the text for the file :\n");
         fgets(array1, 100, stdin);   //return type string
         
         
         
         write(file,array1,strlen(array1)+1);
         //writing to fifo        
         close(file);
         unlink(Fifo);
         
         
         printf("----Reading file--- \n");
        // printf()
         //for acccesing fifo via reading mode
         file = open(Fifo,O_RDONLY);   //O_RDONLY +== Read only
         read(file, array1, sizeof(array1)); 
         printf("message -->  %s \n", array1);
         
         
         for(i=0;i<strlen(array1);i++)
         {
         	if(array1[i]== ' '  || array1[i]=='\n')
         	{
         	     w++;
         	}
         	else
         	    c++;
         	    
                if(array1[i] == '\n')
         	    l++;
             
         }    
             
         printf("number of words : %d \n number of lines : %d \n number of characters : %d \n", w,l,c);        
         close(file);
         printf(" ----File closed---- \n\n");    
         
    
    }
    
    
    


}
