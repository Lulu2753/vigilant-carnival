#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m[1000],a,b[10],i,d[10]={0},count=0,digit,result=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&m[i]);
    }


     for(i=0;i<n;i++)
    {

        a=m[i];

        if(a==0)     //统计数字本身为0的情况
        {
            d[0]++;

        }
        else
        {
            while(a!=0)
            {
                digit=a%10;
                a=a/10;

                d[digit]++;

            }
        }



    }

    for(digit=0;digit<10;digit++)
    {
        if(d[digit]>=count)
        {
            count=d[digit];


        }
    }

    for(i=0;i<10;i++)
    {
        if(d[i]==count)
        {
            b[result]=i;
            result++;
        }

    }


    printf("%d:",count);

    for(i=0;i<result;i++)
        printf(" %d",b[i]);


    return 0;
}
