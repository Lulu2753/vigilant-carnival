#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y,m=2000;
    scanf("%d",&y);

    if(y<=2000||y>2100)
        printf("Invalid year!");

    else if(y>=2004&&y<=2100)
        while(m<=y)
    {
       m++;

       if((m%4==0&&m%100!=0)||m%400==0)

        printf("%d\n",m);
    }





    else printf("None\n");





    return 0;
}
