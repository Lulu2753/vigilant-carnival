#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,price,i=1;
    float p;

    scanf("%d%d",&n,&price);

    while(1)
    {
        scanf("%f",&p);
        i++;

        if(p<price)
            printf("On Sale! %.1f\n",p);

        if(i>n)
            break;

    }


    return 0;
}
