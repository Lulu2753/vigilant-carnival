#include <stdio.h>

#define NONSPACE 'a'

int main()
{
    int c, lastc;

    lastc = NONSPACE;  //最开始将lastc设置任意一个不是空格的值，因为第一次第一个如果是空格，会用到，再记录上一个c

    while((c = getchar()) != EOF)
    {
        if(c != ' ')
            putchar(c);
        if(c == ' ')
            if(lastc != ' ')
                putchar(c);
        
        lastc = c;
    }
}