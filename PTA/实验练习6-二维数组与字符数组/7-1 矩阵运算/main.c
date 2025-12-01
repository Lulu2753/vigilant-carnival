#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,m[10][10],sum=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&m[i][j]);
        }

    }

    for(i=0;i<n-1;i++)
    {
       for(j=0;j<n-1;j++)
       {
          if(i+j==n-1)
            continue;
          sum+=m[i][j];

       }


    }


    printf("%d",sum);

    return 0;
}
