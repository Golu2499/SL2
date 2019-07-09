#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
 
  int i,count=5,number[25];
  
   pid_t pid = fork;   //forkin'
  
  printf("Enter %d elements: ", count);
  for(i=0;i<count;i++)
   {
     scanf("%d",&number[i]);
   }
 
  if(pid == 0)
  {
      printf("This is a child class\n");
      printf("Process id for child class is %d" , getpid());
      printf("\nProcess id for parent class is %d" , getppid());
  }
  else if(pid > 0) //parent process
   {
       sleep(5);
       printf("\nInside parent process\n");
       printf(" parent id is %d" , getpid());
       
       
       quicksort(number,0,count-1);
   		 printf("Order of Sorted elements: ");
   		for(i=0;i<count;i++)
       	  printf(" %d",number[i]);

       
   }
   else
   {
     printf("Process failed ...");
   }

}

int binarysearch()
{
    int arr[50],i,n,x,flag=0,first,last,mid;
 
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("\nEnter array element(ascending order)\n");
 
    for(i=0;i<n;++i)
        scanf("%d",&arr[i]);
 
    printf("\nEnter the element to search:");
    scanf("%d",&x);
 
    first=0;
    last=n-1;
 
    while(first<=last)
    {
        mid=(first+last)/2;
 
        if(x==arr[mid]){
            flag=1;
            break;
        }
        else
            if(x>arr[mid])
                first=mid+1;
            else
                last=mid-1;
    }
 
    if(flag==1)
        printf("\nElement found at position %d",mid+1);
    else
        printf("\nElement not found");
 
    return 0;
}


void quicksort(int number[25],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);

   }
}


