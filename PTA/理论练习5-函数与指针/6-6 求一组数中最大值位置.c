#include <stdio.h>
int fun(int a[], int n);
int main()
{
    int a[10], i;
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);
    printf("%d", fun(a, 10));
    return 0;
}

int fun(int a[], int n)
{
    int i, b, max, j;
    max = a[0];

    for (i = 0; i < n; i++)
    {
        int flag = 1;

        for (j = 0; j < n; j++)
        {
            if (i != j && a[i] < a[j])
                flag = 0;
        }

        if (flag == 1)
        {
            b = i;
            break;
        }
    }

    return b;
}