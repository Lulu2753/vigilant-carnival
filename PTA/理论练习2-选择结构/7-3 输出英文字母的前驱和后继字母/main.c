#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a,b;
    int x,y;

    a=getchar();


    if (a==65||a==97)
    {
        x=a+25;
        y=a+1;

    printf("%c %d\n",x,x);
    printf("%c %d\n",y,y);



    }


    else if (a==90||a==122)

    {
        x=a-1;
        y=a-25;

    printf("%c %d\n",x,x);
    printf("%c %d\n",y,y);

    }


    else

    {
        x=a-1;
        y=a+1;

        printf("%c %d\n",x,x);  //不能重复在里面放putchar，c本身起转换作用
        printf("%c %d\n",y,y);


    }




    return 0;
}
