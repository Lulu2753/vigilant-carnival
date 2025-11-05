#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a, b, c, max;

    scanf("%d %d %d", &a, &b, &c);
    max = 0;
    if ( a > b ) {
        if ( a > c ) {
            max=a;


        } else {
            max=b;


        }
    } else {
        if (b>c)

 {
            max = b;
        } else {
            max=c;


        }
    }
    printf("%d\n", max);

    return 0;
}

