#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n,m,flag,i,j,found=0;

    scanf("%d",&n);

    for(i=2;i<=n;i++)
        {
            m=pow(2,i)-1;
            flag=1;

           for(j=2;j<m;j++)
           {
               if(m%j==0)
                flag=0;
           }



            if(flag==1)
            {
                printf("%d\n",m);
                found=1;
            }


        }

        if(found==0)
            printf("None");



    return 0;
}
