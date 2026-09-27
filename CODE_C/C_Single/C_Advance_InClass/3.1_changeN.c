#include <stdio.h>

// 求一维数组中的最大值和最小值
void search(int x[], int n, int *pmax, int *pmin)
{
    *pmax = *pmin = x[0];

    for (int i = 1; i < n; i++)
    {
        if (*pmax < x[i])
            *pmax = x[i];
        if (*pmin > x[i])
            *pmin = x[i];
    }
}

int main()
{
    int a[20], max, min;

    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &a[i]);
    }
    search(a, 20, &max, &min);
    printf("Max: %d, Min: %d\n", max, min);
    return 0;
}