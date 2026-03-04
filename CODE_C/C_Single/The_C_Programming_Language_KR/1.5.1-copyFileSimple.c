#include <stdio.h>

int main()
{
    int c;
    
    while((c = getchar()) != EOF)  //while里面首先执行getchar
    //!=的优先级高于=，所以这里必须括号，否则先执行不等号
        putchar(c);
}