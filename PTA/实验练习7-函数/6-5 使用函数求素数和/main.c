#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime( int p )
{
    int i;

    if(p<2)
        return 0;

    if(p==2)
        return 1;

    if(p%2==0)
        return 0;     //一旦return后面都不执行

    for(i=3;i<=sqrt(p);i+=2)
    {
        if(p%i==0)
            return 0;
    }

    return 1;

}



int PrimeSum( int m, int n )
{
    int sum=0,i;

    for(i=m;i<=n;i++)
    {
        if(prime(i)!=0)
            sum+=i;
    }

    return sum;

}
