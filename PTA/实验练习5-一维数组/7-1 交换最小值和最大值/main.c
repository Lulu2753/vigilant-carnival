#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[10],i,j,k,m,max,min,a=0,b=0;

    scanf("%d",&m);

    for(i=0;i<=m-1;i++)
    {
        scanf("%d",&n[i]);
    }


    min=n[0];

    for(k=0;k<m;k++)
    {
        if(n[k]<=min)
        {
            min=n[k];
            b=k;
        }
    }

    n[b]=n[0];
    n[0]=min;


    max=n[0];

    for(j=1;j<m;j++)
    {
        if(n[j]>=max  )
        {
            max=n[j];
            a=j;
        }

    }

    n[a]=n[m-1];
    n[m-1]=max;


    for(i=0;i<=m-1;i++)

    {
        printf("%d ",n[i]);

    }



    return 0;
}
