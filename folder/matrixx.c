#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>/

struct in{
   int r,c;
   
};


int *a,*b,*c;   //matrix 1 and 2 and resultant matrix
int r1,r2,c1,c2;   //row and col

int main(){


    pthread_t *thread;
    int ch=0;
    int i,j,count=0;
    in *x; //struct index
    
    //taking input for matrix
    
    do{
    	printf("Enter the number of rows and column in matrix 1 : \n");
    	scanf("%d %d", &r1,&c1);
    	
    	printf("no of rows and col in a are: %d %d" , r1,c1);
    	
    	printf("Enter the number of rows and columns in matrix 2 : \n");
    	scanf("%d  %d", &r2,%c2);
    	
    	
    	printf("no of rows and col in b are: %d %d" , r2,c2);
    
    	if(r2!=c1)
    		{
    		   ch = 1;
    		   printf(" Matrix Multiplication is invalid. \n");
    		}
       }while(ch=0);
    
    a = (int*)malloc(r1*sizeof(int));
    for(int k=0;k<r1;k++)
    {
        a[k] = (int*)malloc(c1*sizeof(int));
    }
    
    
    b = (int*)malloc(r2*sizeof(int));    //dynamically allocating row
    for(k=0;k<r1;k++)     
    {
        b[k] = (int*)malloc(c2*sizeof(int));  //dynamically allocating each column of the row
    }
    
   //r2 c1
    c = (int*)malloc(r2*sizeof(int));
    for(k=0;k<r2;k++)
    {
        c[k] = (int*)malloc(c1*sizeof(int));
       //why do we need to dynamically allocate res matrix ?
    }
    
    
    
    
    
    printf("Enter the elements of matrix 1:\n");
    for(i=0;i<r1;i++)
       {
           for(j=0;j<c1;j++)
             {
                 scanf("%d", &a[i][j]);
       
             }
             
       }
       
       
   printf("Enter the elements of matrix 2: \n");
   for(i=0;i<r2;i++)
      {
          for(j=0;j<c2;j++)
             {
                 scanf("%d", &b[i][j]);
             }
      }
      
      
  
	x = (in*)malloc(r1*c2*sizeof(in));
        threads = (pthread_t*)malloc(r1*c2*sizeof(pthread_t))
        
        for(i=0;i<r1;i++)
          {
            for(j=0;j<c2;j++)
               {
                  x[count].r=i;
                  x[count].c=j;
                  //creation of thread for multiplication
                  check = pthread_create(threads, ,multiplication,&x[count]);    
                  //pthread_Create(pthread_t *thread, const pthread_attr_t *Attr, void*(*start_routine)(void *),void *arg)
                  //returns zero on success
                  count++;
                  
               }
          }
          
          
       for(i=0;i<count;i++)
         {
            check = pthread_join(threads[i],0);
            //pthread_join(pthread_t *thread,void **retval);
            //returns 0 success
            
            if(check==0)
            {
                printf("Threads were joined \n");
            }
            else
            {
                printf("Threads were not joined \n\n");
            }
         }   
        
        
        
        
        
	printf("\n\tMatrix no 1:\n");
	print_matrix(r1,c1,a);
	
	printf("\n\tMatrix no 2:\n");
	print_matrix(r2,c2,b);
	
	printf("\n\tResultant matrix :\n");
	print_matrix(r1,c2,c);
        return 0;

        
}

int multiplication(void x)
{
    in x2;
    int row,column;
    
    row = x2.r;
    column = x2.c;
    
    for(int z=0 ; z<c1 ; z++)
       {
         sum += a[r][i]*b[i][c];
       }    

    c[row][column] = sum;
   
    pthread_exit(3);  //function would exit the thread after 3 seconds
    
    return 0;
}

int print_matrix(int row,int column, int *matrix)
{
    for(i=0;i<row;i++)
       {
          printf("\n\t");
          for(j=0;j<column;j++)
          {
              printf("%d", c[i][j]);
          
          }
          printf("\n\n");
       }

}



        
	
