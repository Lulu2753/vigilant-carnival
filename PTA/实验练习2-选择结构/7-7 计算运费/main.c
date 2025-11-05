#include <stdio.h>
#include <stdlib.h>

int main()
{
    float p,w,s,d,f;
    scanf("%f %f %f",&p,&w,&s);

    if (s<250)
        d=0;
    else if (250<=s&&s<500)
        d=0.02;
    else if (500<=s&&s<1000)
        d=0.05;
    else if (1000<=s&&s<2000)
        d=0.08;
    else if (2000<=s&&s<3000)
        d=0.1;
    else
        d=0.15;

    f=p*w*s*(1-d);

    printf("freight=%.2f",f);



    return 0;
}
