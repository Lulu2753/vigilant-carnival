#include<stdio.h>
#include<math.h>

int rootOfEquation(double a, double b, double c, double* x1, double* x2);

int main()
{
    double a, b, c;
    double x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    int flag;
    flag = rootOfEquation(a, b, c, &x1, &x2);
    if (flag == 0)
        printf("方程无实根");
    else if (flag == 1)
        printf("方程有两个相等的实根 x1=x2=%.2f", x1);
    else
        printf("方程有两个不等的实根 x1=%.2f,x2=%.2f", x1, x2);
    return 0;
}

int rootOfEquation(double a, double b, double c, double* x1, double* x2)
{
    double delta;
    delta = b * b - 4 * a * c;

    if (delta < 0)
        return 0;
    else if (delta == 0)
    {
        *x1 = *x2 = -b / 2.0 / a;
        return 1;
    }
        
    else
    {
        *x1 = (-b + sqrt(delta)) / (2.0 * a);
        *x2 = (-b - sqrt(delta)) / (2.0 * a);//分母一定要括号括起来

        return 2;
    }
}
