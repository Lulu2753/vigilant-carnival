#include <stdio.h>

int is( int number );
void count_sum( int a, int b );

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);
    if (is(a)) printf("%d is counted.\n", a);
    if (is(b)) printf("%d is counted.\n", b);
    count_sum(a, b);

    return 0;
}


int is( int number )
{
    int d=0;

    do
    {
        d+=number%10;
        number/=10;

    }while(number>0);

    if(d==5)
        return 1;

    return 0;
}

void count_sum( int a, int b )
{

    int i,sum=0,count=0;
    for(i=a;i<=b;i++)
    {
        if(is(i)==1)
        {
            sum+=i;
            count++;
        }
    }

    printf("count = %d, sum = %d\n",count,sum);
}
