#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,i;

    scanf("%d%d",&m,&n);

    if(m>=n)
        i=n;
    else
        i=m;

    while(m%i!=0||n%i!=0)
        i--;

    printf("%d %d",i,m*n/i);

    return 0;


}
