#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int D,a,b,h,m;
    float x;

    scanf("%d %d %d", &D,&a,&b);

    x=D*1.0/(a+b);

    h=(int)x;
    m=ceil((D*1.0/(a+b)-h)*60);

    printf("%dСʱ%d����",h,m);






    return 0;
}
