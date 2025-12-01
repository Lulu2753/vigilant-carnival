#include <stdio.h>
#include <stdlib.h>

int main()
{
     int i,j,n,k,m[20][20],flag=0;

    scanf("%d %d",&n,&k);

    for(i=0;i<n;i++)
    {
        for(j=0;j<k;j++)
        {
            scanf("%d",&m[i][j]);
        }

    }

    for(i=1;i<n-1;i++)
    {
       for(j=1;j<k-1;j++)
       {



          if(m[i][j]>m[i-1][j]&&m[i][j]>m[i][j-1]&&m[i][j]>m[i+1][j]&&m[i][j]>m[i][j+1])
          {
              printf("%d %d %d\n",m[i][j],i+1,j+1);
              flag=1;
          }
       }


    }



    if(flag==0)
        printf("None %d %d",n,k);

    return 0;
}
