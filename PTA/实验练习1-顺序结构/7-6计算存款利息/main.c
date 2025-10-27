#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int money;
    double year,rate,interest;

    scanf("%d %lf %lf",&money,&year,&rate);

    interest=money*pow(1+rate,year)-money;

    printf("interest = %.2f",interest);

    return 0;
}
