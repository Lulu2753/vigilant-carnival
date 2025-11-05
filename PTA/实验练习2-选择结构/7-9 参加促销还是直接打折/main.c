#include <stdio.h>
#include <stdlib.h>

int main()
{
    float m,x,y;
    scanf("%f",&m);


    if (m<100)
        x=m;
    else if (100<=m&&m<200)
        x=m-10;
    else if (200<=m&&m<400)
        x=m-25;
    else if (400<=m)
        x=m-55;

    y=0.9*m;


    if (x-y>=0)
    {
         printf("不参加活动，直接9折\n");
         printf("节约%.1f元",m-y);
    }

    else if (x-y<0)
    {

        if (100<=m&&m<200)
        {
            printf("参加活动，满100返10元\n");
            printf("节约%.1f元",m-x);
        }

        else if (200<=m&&m<400)
        {
            printf("参加活动，满200返25元\n");
            printf("节约%.1f元",m-x);
        }

        else if (400<=m)
        {
            printf("参加活动，满400返55元\n");
            printf("节约%.1f元",m-x);
        }


    }



    return 0;
}
