#include <stdio.h>

int main(void)
{
    int n[10];
    for (int i = 0; i < 10; i++)
    {
        printf("type a number: ");
        scanf("%d", &n[i]);
    }
    for (int j = 0; j < 10; j++)
    {
        printf("%d,", n[j]);
    }
    printf("\n");
}