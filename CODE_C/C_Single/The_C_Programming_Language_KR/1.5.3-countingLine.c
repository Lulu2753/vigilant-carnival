#include <stdio.h>

int main()
{
    int c, nl;

    nl = 0;
    while((c = getchar()) != EOF)
        if(c == '\n')    //单引号表示ASCII码,以换行符定义新行
            ++nl;
    printf("%d\n", nl);
}