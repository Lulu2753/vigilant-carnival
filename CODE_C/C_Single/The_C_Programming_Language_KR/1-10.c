#include <stdio.h>

int main()
{
    int c;

    while((c = getchar()) != EOF)
    {
        if(c == '\t')
            printf("\\t");  //反斜杠一律都是\\, 和不同字母组合即可
        if(c == '\b')
            printf("\\b");
        if(c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}