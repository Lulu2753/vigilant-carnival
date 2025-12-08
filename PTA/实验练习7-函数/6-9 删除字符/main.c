#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);

    return 0;
}


void delchar( char *str, char c )
{
    int i;

    for(i=0;*str!=0;str++)
    {
        if(*(str+i)!=c)    //*(str+i)实际上就是s[i],因为s[0]就是*str
            *str=*(str+i);  //如果有删除的i！=0，就在这里往前移动
        else
        {
            i++;
            str--;   //+1回退用来覆盖
        }
    }

}


void ReadString( char s[] )
{
    int i=0;
    char c;

    while((c=getchar())!='\n')
    {
        s[i]=c;
        i++;
    }
    s[i]='\0';
}
