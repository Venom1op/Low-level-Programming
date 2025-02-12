#include "allocator.h"
#include <stdio.h>

int main() {
    int n;
    printf( "Enter the number : ");
    scanf("%d",&n);
    
    // Allocate space for an array of 5 integers
    int *arr = (int *)my_malloc(n * sizeof(int));

    if (!arr) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Assign values to the array
    for (int i = 1; i <= n; i++) {
        printf( "Enter the elements : %d  : \n",i);
        scanf("%d",&arr[i]);
    }

    // Print values
    printf("Dynamic Array:\n");
    for (int i = 1; i <=n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free the allocated memory
    my_free(arr);

    return 0;
}
