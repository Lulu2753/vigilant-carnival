#include <stdio.h>
#define MAXLINE 1000  //防止溢出

int getline(char s[], int lim);
int removing(char s[]);

int main()
{
    char line[MAXLINE];

    while(getline(line, MAXLINE) > 0)
    {
        if(removing(line) > 0)
            printf("%s", line);    //统一输出需要二维数组
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

    if(c == '\n')
        {
            s[j] = '\n';
            ++i;
            ++j;
        }

    s[j] = '\0';
    return i;
}

int removing(char s[])
{
    int i;
    i=0;

    while(s[i] != '\n')
        ++i;
    --i;   //索引从0开始，所以上面到i时实际上是\n
    
    while(i >= 0 && (s[i] == ' '||s[i] == '\t'))
        --i;
    
    if(i >= 0)
    {
        ++i;
        s[i] = '\n';  
        ++i;
        s[i] = '\0';
    }

    return i;    //返回非零值说明不全是空格，可以打印
}