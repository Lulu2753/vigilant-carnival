#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x,y;
    scanf("%lf",&x);

    if (x>=0)
       {
           y=pow(x,0.5);
           printf("f(%.2lf) = %.2lf",x,y);
       }

    if (x<0)
    {
        y=pow((x+1),2)+2*x+1.0/x;
        printf("f(%.2lf) = %.2lf",x,y);
    }



    return 0;
}
