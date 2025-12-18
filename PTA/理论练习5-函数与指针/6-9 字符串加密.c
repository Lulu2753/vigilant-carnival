#include<stdio.h>
#include<string.h>
void cryptograp(char ch[], int n);    //加密函数

int main()
{
    int count = 0;
    char text[80] = { '\0' };            //存放明文字符串

    gets(text);
    count = strlen(text);
    cryptograp(text, count);
    printf("加密后的密文是:\n%s\n", text);
    return 0;
}

void cryptograp(char ch[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if ((ch[i] >= 'A' && ch[i] <= 'U') || (ch[i] >= 'a' && ch[i] <= 'u'))
        {
            ch[i] += 5;
        }

        else if ((ch[i] >= 'V' && ch[i] <= 'Z') || (ch[i] >= 'v' && ch[i] <= 'z'))
        {
            ch[i] = ch[i] - 21;
        }
    }
}