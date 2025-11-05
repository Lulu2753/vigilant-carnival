#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,y,a,b,h,m;
    scanf("%d%d",&x,&y);

    a=x/100*60+x%100;
    b=y/100*60+y%100;

    h=(b-a)/60;
    m=(b-a)%60;

    printf("%02d:%02d",h,m);



    return 0;
}
