#include <stdio.h>

char *strcopy(char *str1, char *str2) // 星号表示该函数返回一个字符指针
{
    char *s = str1;        // 指针变量
    while (*str2)          // 遇到终止符就跳出循环了（括号里为0）
        *str1++ = *str2++; // 右结合，先str自增再取内容，复制

    *str1 = '\0';

    return s; // 返回的是指针
}

void main()
{
    char *ps, s1[80] = "yhhhhj";
    ps = strcopy(s1, "yyyjh");

    puts(ps);
}