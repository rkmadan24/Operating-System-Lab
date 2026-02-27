#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

 // Duplicates in a Array

 for(i=0;i<n;i++)
    {
       for(int j=i+1;j<n;j++)
       {
           if(a[i]==a[j])
           {
               printf("Duplicate element %d is present ",a[i]);
           }
       }
    }

    return 0;
}

