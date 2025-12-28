#include <stdio.h> 
#include <string.h>

char* match(char* s, char ch);

int main(void)
{
    char ch, str[80], * p = NULL;

    scanf_s("%s", str,sizeof(str));
    getchar();                 /* 跳过输入字符串和输入字符之间的分隔符 */
    ch = getchar();          /* 输入一个字符 */
    p = match(str, ch);     /* 调用函数match() */
    if (p != NULL) {        /* 找到字符ch */
        printf("%s\n", p);
    }
    else {
        printf("Not Found.\n");
    }

    return 0;
}

char* match(char* s, char ch)
{
    int i, * l, flag = 0;
    l = s;

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == ch)
        {
            l=s+i;
            flag = 1;
        }
    }

    if (flag == 0)
        return NULL;

    else if (flag == 1)
        return l;


}