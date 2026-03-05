#include <stdio.h>

int main()
{
    int c, i, nwhite, nother;
    int ndigit[10];  //分别统计十个数字

    nwhite = nother = 0;
    for(i = 0; i < 10; ++i)
        ndigit[i] = 0;

    while((c = getchar()) != EOF)
    {
        if(c >= '0' && c <= '9')  //因为是getchar所以必须要用字符ASCII码的形式
            ++ndigit[c - '0'];
        else if(c == ' ' || c == '\n' || c == '\t')
            ++nwhite;
        else 
            ++nother;
    }

    printf("digits =");

    for(i = 0; i < 10; ++i)
        printf(" %d", ndigit[i]);
    printf(", white space = %d, other = %d\n",
        nwhite, nother);

}