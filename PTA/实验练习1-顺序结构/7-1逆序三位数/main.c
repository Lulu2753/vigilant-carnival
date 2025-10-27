#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d,e;

    scanf("%d",&a);

    b=a/100;  //百位
    d=a%10;  //个位
    c=(a-100*b)/10;  //十位

    e=d*100+c*10+b;


    printf("%d\n",e);

    return 0;

}
