#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=1,n,f=1;
    float s=0;

    scanf("%d",&n);

    while(i<=n)

    {
        s=s+i*1.0*f/(2*i-1);
        i++;
        f=-f;
    }
    printf("%.3f",s);

    return 0;

}


