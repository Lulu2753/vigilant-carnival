#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,k,i,m,j,flag,count=0,sum=0;

    scanf("%d%d",&n,&k);

    for(i=n-1;i>1;i--)
    {

        flag=1;


        for(j=2;j<i;j++)
        {
            if(i%j==0)
                flag=0;

        }

        if(flag==1)
        {
            count++;

            if(count>k)

                    break;



            m=i;
            sum+=m;



            if(count==1)
                printf("%d",m);
            else if(count!=1)
                printf("+%d",m);



        }

    }


    printf("=%d",sum);



    return 0;
}
