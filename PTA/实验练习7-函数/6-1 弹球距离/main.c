#include <stdio.h>
#include <stdlib.h>
#define TOL 1E-3

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

double dist(double h,double p)
{
    double d=h;

    while(1)
    {
         h*=p;//算完这个后再判断
         if(h<TOL)
            break;
         d+=2*h;  //还有下降
    }



    return d;
}
