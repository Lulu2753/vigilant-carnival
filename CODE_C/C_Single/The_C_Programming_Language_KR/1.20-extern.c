#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];  //定义在使用的函数之前，声明也可以省略extern，一般放在头文件，extern也会使函数失去通用性

int getline(void);
void copy(void);  //显式声明空参数

/*打印最长行*/
int main()
{
    int len;
    extern int max;
    extern char longest[];   //声明外部变量，不是定义了，定义在外面

    max = 0;
    while((len = getline()) > 0)
        if(len > max)
        {
            max = len;
            copy();
        }
    
    if(max > 0)
        printf("%s", longest);
    
    return 0;
}

int getline(void)   //不用传递参数了
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE-1 
        && (c=getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    
    if(c == '\n')    //MAXLINE-2，有换行就填充换行，没到maxline-2也是换行
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';   //无论如何最后都有这个串尾标记
    return i;
}

void copy(void)
{
    int i;
    extern char line[], longest[];

    i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}
