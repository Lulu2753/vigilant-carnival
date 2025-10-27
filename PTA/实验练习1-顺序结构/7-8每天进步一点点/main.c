#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    float a,b,c;


    scanf("%d",&n);

    a=pow(1.01,n);
    b=pow(0.99,n);

    c=a/b*100;

    printf("%.2f %.2f %.1f%%",a,b,c);//输出百分号需要打两个百分号


    return 0;
}
