#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main()
{
    int n,i,j;
    scanf("%d",&n);

    for(i=-(n-1)/2;i<=(n-1)/2;i++)
    {
        for(j=1;j<=fabs(i);j++)
            printf("  ");


        for(j=1;j<=(n-fabs(i)*2);j++)
            printf("* ");

            printf("\n");
    }

    return 0;
}


