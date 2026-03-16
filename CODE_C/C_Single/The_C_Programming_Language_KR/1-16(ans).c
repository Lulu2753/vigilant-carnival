#include <stdio.h>
#define MAXLINE 100  //！！允许的最大行长度

int getline(char line[], int maxline);  //求长度
void copy(char to[], char from[]);

int main()
{
    int len;//当前长度
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while((len = getline(line, MAXLINE)) > 0)
    {
        if(len > max)
        {
            max = len;
            copy(longest, line);
        }
    }

    printf("%d\n", max);  //打印len则最后换行后的空行算进去了

    if(max > 0)
        printf("%s", longest);
    return 0;
}

int getline(char s[], int lim)   //声明参数
{
    int c, i, j;

    j = 0;

    for(i=0; (c=getchar())!=EOF && c!='\n'; ++i)
    {
        if(i < lim - 2)  //数组s的最后一个下标是lim-1，令s[lim-2]='\n'
        {
            s[j] = c;   //字符串
            ++j;
        } 

    }
       
    if(c == '\n')
    {
        s[j] = c;    //lim-2储存可能的换行符      
        ++j;
        ++i;
    }
    s[j] = '\0';  
    return i;   //能够返回真实长度，并被打印
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')   //括号里面赋值
        ++i;
}