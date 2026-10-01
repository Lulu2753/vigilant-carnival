#include <stdio.h>

void max_min(int *x, int n, int *max, int *min);

int main()
{
    int i, a[] = {2, 4, 1, 6, 7, 32, 45, 75, 45, 90}, max, min;
    for (printf("The original array="), i = 0; i < 10; i++)
        printf("%5d", a[i]);

    max_min(a, 10, &max, &min);
    printf("\nmax=%d min=%d", max, min);

    return 0;
}

void max_min(int *x, int n, int *max, int *min) // 全部用指针操作地址
{
    int i;
    *max = *min = *x;            // 先都取首地址
    for (i = 1; i < n; i++, x++) // 数组同时也要移动取不同的值比较，此处i纯粹计数用
    {
        if (*max < *x) // 用x[i]则只需要i自增
            *max = *x;
        if (*min > *x)
            *min = *x;
    }
}