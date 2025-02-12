#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int n, *ptr;
    printf("Enter the Size : ");
    scanf("%d", &n);
    ptr = (int *)calloc(n, sizeof(int));
    if (ptr == NULL)
    {
        printf("Memory Not allocated!!!");
        exit(0);
    }
    else
    {
        printf("Memory allocated!!!");
        for (int i = 0; i < n; i++)
        {
            printf("Enter the element : %d", i);
            scanf("%d", &ptr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            printf(" the element are : %d\n", ptr[i]);
        }
    }
    return 0;
}