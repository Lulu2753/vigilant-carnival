#include <stdio.h>

int main()  
{
    int c;  //声明为int是为了储存足够大的数，任何数都可能是EOF

    c = getchar();  //int也可以字符输入，只能一个数字

    while(c != EOF)
    {
        putchar(c);
        c = getchar();
    }

}