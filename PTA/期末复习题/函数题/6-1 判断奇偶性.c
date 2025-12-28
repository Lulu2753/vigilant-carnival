#include <stdio.h>

int even(int n);

int main()
{
    int n;

    scanf_s("%d", &n);
    if (even(n))
        printf("%d is even.\n", n);
    else
        printf("%d is odd.\n", n);

    return 0;
}

int even(int n)
{
    if (n < 0)
        n = -n;

    return(n % 2 - 1);
}