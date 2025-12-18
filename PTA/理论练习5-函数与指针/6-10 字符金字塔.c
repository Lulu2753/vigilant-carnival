#include <stdio.h>

void CharPyramid(int n, char ch);

int main()
{
    int n;
    char ch;

    scanf_s("%d %c", &n, &ch);
    CharPyramid(n, ch);

    return 0;
}

void CharPyramid(int n, char ch)
{
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)     //i=n就不会执行这个，因为j<=n-i不成立
            printf(" ");
        for (k = 1; k <= i; k++)
            printf("%c ", ch);
        printf("\n");
    }
}
