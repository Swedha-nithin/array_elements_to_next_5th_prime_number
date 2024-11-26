#include<stdio.h>
#include<stdlib.h>

void prime(int *num)
{
   int count =0,i,flag;                // initialising the variables
   
   // for loop starting from the next number of the current elemnt and its runs upto when the 5th prime number accounted
   for( i=(*num)+1; count<5; i++)      
   {
       flag=0;
       // loop to check the number is prime or not
       for(int j=2; j<i; j++)
       {
           if(i%j == 0)
           {
               flag=1;
               break;
           }
       } 
       // if the number is prime, count variable is incremented
       if(flag==0)
       count++;  
   }
   *num = (i-1);// array element is changed as the 5th prime number
}



int main()
{
    // initialising the variables and prompt for rows and columns
    int row,col;
    printf("Enter the number of rows\n");
    scanf("%d", &row);
    printf("Enter the number of columns\n");
    scanf("%d", &col);
    
    // declaring array dynamically
    int ** arr = malloc(row*sizeof(int));
    for(int i=0; i<row;i++)
    {
        arr[i] = malloc(col*sizeof(int));
    }
    
    // reading array elements
    printf("Enter the array elements\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {       
            scanf("%d", &arr[i][j]);
        }
    }
    
    // printing array elements before modification
    printf("Array elemnts are\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {       
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    // calling function and passing array as elemnent by element 
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {       
            prime(&arr[i][j]);
        }
    }
    // printing array elements after modification
    printf("Array elemnts after modification are\n");
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {       
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
