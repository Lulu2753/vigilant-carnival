#include <stdio.h>
#include "game_test.h"

int main()
{
    int a=2,b=3;
    printf("Before: a=%d, b=%d\n",a,b);

    swap(&a,&b);

    printf("After: a=%d, b=%d\n",a,b);

    return 0;
}