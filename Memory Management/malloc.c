#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int *ptr;
    int n;
    printf("Enter the Size of the Elements : ");
    scanf("%d", &n);
    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Not Allocated!!");
        exit(0);
    }
    else
    {
        printf("Memory Allocated Successfully!! \n");
        for (int i = 0; i < n; i++)
        {
            printf("Enter the First Element %d :",i);
            scanf("%d", &ptr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", ptr[i]);
        }
    }
    return 0;
}