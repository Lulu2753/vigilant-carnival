#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* 实现细节在此不表 */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);

    return 0;
}


void Shift( char s[] )
{
    char a[3];//保存前三个字符
    int i,j;

    for(i=0;i<3;i++)
    {
        a[i]=s[i];
    }


    for(i=3;s[i]!='\0';i++)
    {
        s[i-3]=s[i];    //是移动不是交换
    }



    for(j=0;j<3;j++)
    {
        s[strlen(s)-3+j]=a[j];
    }

}

void GetString( char s[] )
{
    int i=1;
    char c;//用来中转

    s[0]=getchar();

    while((c=getchar())!='\n')
    {
        s[i]=c;
        i++;
    }
    s[i]='\0';

}
