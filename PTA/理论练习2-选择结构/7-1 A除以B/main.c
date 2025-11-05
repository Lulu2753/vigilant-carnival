#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;
    float y;

    scanf("%d %d",&a,&b);

    y=1.0*a/b;

    if (b==0)
    {
        printf("%d/%d=Error",a,b);
    }

    else if (b<0)
    {
        printf("%d/(%d)=%.2f",a,b,y);
    }

    else
    {
        printf("%d/%d=%.2f",a,b,y);
    }

    return 0;
}
