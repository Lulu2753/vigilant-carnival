#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int ip[4][8],i,j,p[4]={0};

    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
            scanf("%1d",&ip[i][j]);

        }
    }

    for(i=0;i<4;i++)
    {
        for(j=0;j<8;j++)
        {
            p[i]+=ip[i][j]*pow(2,7-j);

        }


    }


    printf("%d",p[0]);

    for(i=1;i<4;i++)
        printf(".%d",p[i]);



    return 0;
}
