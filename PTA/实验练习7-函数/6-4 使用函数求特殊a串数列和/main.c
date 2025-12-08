#include <stdio.h>

int fn( int a, int n );
int SumA( int a, int n );

int main()
{
    int a, n;

    scanf("%d %d", &a, &n);
    printf("fn(%d, %d) = %d\n", a, n, fn(a,n));
    printf("s = %d\n", SumA(a,n));

    return 0;
}

int fn( int a, int n )
{
    int d=0,count=1;

    do
    {
        d*=10;   //先乘10再加a，此时count应为第一次
        d+=a;

        count++;
    }while(count<=n);

    return d;


}



int SumA( int a, int n )
{

    int sum=0,i;

    for(i=1;i<=n;i++)
        sum+=fn(a,i);


    return sum;
}
