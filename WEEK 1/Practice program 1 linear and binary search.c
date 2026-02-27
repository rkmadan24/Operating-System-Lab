#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements: ");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }


// Linear search
    int key,found=0;
    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Element %d is present at position %d\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found)
    {
        printf("Element %d not found\n", key);
    }


// Binary search
    int start=0,end=n-1,mid;
    found=0;
    while(start<=end) {
        mid=(start + end)/2;
        if(a[mid]==key)
        {
            printf("Element %d is present at position %d \n",key,mid);
            found=1;
            break;
        }
        else if (key<a[mid])
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if (found==0)
    {
        printf("Element %d not found in Binary Search\n", key);
    }

    return 0;
}
