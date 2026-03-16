#include <stdio.h>
#define MAXLINE 100  //！！允许的最大行长度

/*
    while(还有未处理的行)
        if(该行比前面的max还长)
            保存该行及长度；
    打印最长行
*/

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

    if(max > 0)
        printf("%s", longest);
    return 0;
}

int getline(char s[], int lim)   //声明参数
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)  //没有把这一行读完，截断到lim-1
        s[i] = c;   //字符串  //一个汉字占两个字符
    if(c == '\n')   //！！如果因为遇到换行符而结束，被截断说明这里不是换行！！！！，所以直接往下储存串尾标记！！
    {
        s[i] = c;      
        ++i;
    }
    s[i] = '\0';  //最后一个要存储串尾标记，所以上面lim-1，并且防止越界
    return i;
}

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')   //括号里面赋值
        ++i;
}