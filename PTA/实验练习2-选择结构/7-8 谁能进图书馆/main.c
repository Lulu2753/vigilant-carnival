#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);

    if ((c<a) && (d>=b))
        {
            printf("%d-Y %d-Y\n",c,d);
            printf("qing 2 zhao gu hao 1");

        }

    else if ((d<a) && (c>=b))
    {
        printf("%d-Y %d-Y\n",c,d);
        printf("qing 1 zhao gu hao 2");

    }

    else if ((c<a) && (a<=d&&d<b))
    {
        printf("%d-N %d-Y\n",c,d);
        printf("2: huan ying ru guan");

    }

    else if ((d<a) && (a<=c&&c<b))
    {
        printf("%d-Y %d-N\n",c,d);
        printf("1: huan ying ru guan");

    }

    else if ((c<a) && (d<a))
    {
        printf("%d-N %d-N\n",c,d);
        printf("zhang da zai lai ba");
    }


    else if (c>=a && d>=a)

    {
        printf("%d-Y %d-Y\n",c,d);
        printf("huan ying ru guan");
    }




    return 0;
}
