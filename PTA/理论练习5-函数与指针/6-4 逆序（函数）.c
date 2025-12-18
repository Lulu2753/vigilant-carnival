#include <stdio.h>

void inv(int x[], int n);

int main()
{
    int i, a[100], n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    inv(a, n);
    for (i = 0; i < n; i++)
        printf("%4d", a[i]);
    printf("\n");
    return 0;
}

void inv(int x[], int n)
{
    int t, i;

    for (i = 0; i < n / 2; i++)
    {
        t = x[i];
        x[i] = x[n - 1 - i];
        x[n - 1 - i] = t;
    }
}