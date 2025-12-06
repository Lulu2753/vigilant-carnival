#include <stdio.h>

int main()
{
    char str1[80], str2[81];
    int i;
    gets(str1);
    i = 0;
    while (str1[i] != '\0')
    {

        str2[i] = str1[i];
        i++;
    }
    str2[i] = '\0';   //不加这个会出现未知错误，后面会有一堆随机加的
    puts(str2);
}

