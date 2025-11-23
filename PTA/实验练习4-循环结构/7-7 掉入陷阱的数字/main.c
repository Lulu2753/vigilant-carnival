#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dsum,n,i[100],count=0;

    scanf("%d",&i[0]);

    do
    {

        dsum=0;

        n=i[count];

        while(n>0)
        {
            dsum+=n%10;
            n/=10;
        }

        count++;

        i[count]=dsum*3+1;

        printf("%d:%d\n",count,i[count]);



    }while(i[count]!=i[count-1]);


    return 0;
}
