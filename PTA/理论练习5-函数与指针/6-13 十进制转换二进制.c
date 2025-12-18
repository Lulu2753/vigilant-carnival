#include <stdio.h>
#include <math.h>

void dectobin(int n);

int main()
{
    int n;

    scanf_s("%d", &n);
    dectobin(n);

    return 0;
}

void dectobin(int n)
{
    int m=0, k = 0;

    while (n != 0)
    {
        m+=(n % 2) * pow(10, k);
        k++;
        n /= 2;
    }


    printf("%d", m);
}
