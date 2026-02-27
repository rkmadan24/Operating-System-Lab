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

// Find smallest element
    int smallest = a[0];
    int pos = 0;
    for (i = 1; i < n; i++) {
        if (a[i] < smallest) {
            smallest = a[i];
            pos = i;
        }
    }
    printf("Smallest element is: %d\n", smallest);
    printf("Position: %d\n", pos);

    return 0;
}
