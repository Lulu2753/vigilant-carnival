#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned a,b,c,d,n;

    scanf("%u",&n);

    a=n/100;
    b=(n-100*a)/10;
    c=(n-100*a)%10;

    d=a+b+c;

    printf("%d",d);
    return 0;
}
