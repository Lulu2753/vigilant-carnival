#include <stdio.h>
#define MAXLINE 10000
#define LONGLINE 20

int getline(char s[], int lim);

int main()
{
    int len;
    char line[MAXLINE];

    while((len = getline(line, MAXLINE)) > 0)    //不用触发EOF，只要有换行就有len，因为printf在循环内部！
    {
        printf("%d\n", len);

        if(len > LONGLINE)
            printf("%s", line);    //单纯的line表示这个字符串
    }

    return 0;

}

int getline(char s[], int lim)
{
    int c, i, j;

    j = 0;

    for(i=0; (c=getchar())!=EOF && c!='\n' && i<lim-2; ++i)
    {
        s[j] = c;
        ++j;
    }

    if(c == '\n')    //如果第lim-2个（从0开始数）是换行，不是的话直接填充\0，实际上字符数是lim-2个了
    {
        s[j] = c;
        ++j;
        ++i;
    }

    s[j] = '\0';

    return i;

}
