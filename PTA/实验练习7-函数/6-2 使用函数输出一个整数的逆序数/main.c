#include <stdio.h>

int reverse( int number );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}

int reverse( int number )
{
    int d,s=0,n;
    n=number;
    if(number<0)
        number=-number;

    while(number>0)
    {
        s*=10;
        d=number%10;
        number/=10;
        s+=d;

    }

    if(n<0)
        return -s;
    else
        return s;
}
