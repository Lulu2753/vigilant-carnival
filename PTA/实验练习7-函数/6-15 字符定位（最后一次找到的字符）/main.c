#include <stdio.h>

char *match(char *s, char ch);

int main(void )
{
    char ch, str[80], *p = NULL;

    scanf("%s", str);
    getchar();                 /* 跳过输入字符串和输入字符之间的分隔符 */
    ch = getchar();          /* 输入一个字符 */
    p = match(str, ch);     /* 调用函数match() */


    if( p != NULL ) /* 找到字符ch */

    {
        printf("%s\n", p);
    }


    else
    {


        printf("Not Found.\n");
    }

    return 0;
}


char *match(char *s, char ch)
{
    char *p=s;   //整个串赋值给指针


    while(*p!=0)
        p++;

    p--;
    while(p>=s)
    {
        if(*p==ch)
            return p;    //从后往前找，一旦return就是那个值

            p--;

    }


    return NULL;

}
