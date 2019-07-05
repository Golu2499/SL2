#include<stdio.h>
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
int main() 
{ 
    // Fork returns process id 
    // in parent process 
    
    
    
    int i, count, arr[25];

   printf("How many elements are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d elements: ", count);
   for(i=0;i<count;i++)
      scanf("%d",&arr[i]);

    
  // int arr[] = {12, 11, 13, 5, 6, 7}; 
    
    
   
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    
    
    printf("\nGiven array is \n"); 
    printArray(arr, arr_size); 
  
  //  mergeSort(arr, 0, arr_size - 1); 
  
   // printf("\nSorted array is \n"); 
   // printArray(arr, arr_size); 
    
    pid_t cpid = fork(); 
    
  
    // Parent process  
    if (cpid > 0) 
    {
        sleep(10);
        printf("\nparent process\n");
        
        printf("\nparent id : %d",  getpid());
        
         mergeSort(arr, 0, arr_size - 1);
          printf("\nSorted array is \n");  
         printArray(arr, arr_size);
        
        
//        printf("child id : %d", cpid()); 
      }
    // Child process 
    else
    {
        printf("\nchild process\n");
        printf("\nchild id : %d", getpid());
        printf("\nparent id : %d", getppid());
        exit(0); 
     }
     
     
     printf("\ncontrol returned to parent");
    return 0; 
} 


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 
  
/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 



void scanArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        scanf("%d ", A[i]); 
    scanf("\n"); 
} 
  
/* Driver program to test above functions */









// QUICK SORT


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





