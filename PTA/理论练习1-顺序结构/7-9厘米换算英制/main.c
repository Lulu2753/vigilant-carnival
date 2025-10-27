#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,f,i,a;

    scanf("%d",&c);

    f=c/30.48;
    i=(c/30.48-f)*12;

   printf("%d %d",f,i);
    return 0;
}
