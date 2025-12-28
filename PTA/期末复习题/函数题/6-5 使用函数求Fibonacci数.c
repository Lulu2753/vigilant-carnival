#include <stdio.h>

int fib(int n);

int main()
{
    int n;

    scanf_s("%d", &n);
    printf("%d\n", fib(n));

    return 0;
}

int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;

    int f1 = 1, f2 = 1, f, i;

    if (n > 2)
    {
        for (i = 3; i <= n;i++)
        {
            f = f1 + f2;
            f1 = f2;
            f2 = f;
        }
       
    }

    return f;
}