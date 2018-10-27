#include<stdio.h>

int arr[100];


void swap(int *no1, int *no2)
{
    int temp = *no1;
    *no1 = *no2;
    *no2 = temp;
}
 

int getTheArray(){
    int max, i;
    printf("\nEnter number of inputs : ");
    scanf("%d", &max);
    printf("\nEnter values :");
    for(i=0;i<max;i++){
        scanf("%d", &arr[i]);
    }
    printf("\nUnsorted array is : ");
    for(i=0;i<max;i++){
        printf("\t%d",arr[i]);
    }
    printf("\n");
    return max;
}

void bubblesort_parent(int n){
    int i, j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
        }    
    }
    printf("\nsorted array is : ");
    for(i=0;i<n;i++){
        printf("\t%d",arr[i]);
    }
    printf("\n");
}

void insertion_child(int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
    printf("\nsorted array is : ");
    for(i=0;i<n;i++){
        printf("\t%d",arr[i]);
    }
    printf("\n");
}

void main() {
	int pid, n;
		
	n=getTheArray();
	
	pid=fork();

        if(pid==0){
            wait();
            printf("\nChild : ");
            insertion_child(n);
        }else{
            
            printf("\nParent Process : ");
            bubblesort_parent(n);
        }

}
