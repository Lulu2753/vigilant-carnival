#include <stdio.h>

int gcd( int x, int y );

int main()
{
    int x, y;

    scanf("%d %d", &x, &y);
    printf("%d\n", gcd(x, y));

    return 0;
}

int gcd( int x, int y )
{
    int d;

    do
    {
        d=x%y;
        x=y;
        y=d;

    }while(d>0);

    return x;

}
