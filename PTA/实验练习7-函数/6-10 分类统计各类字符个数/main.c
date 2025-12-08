#include <stdio.h>
#define MAXS 15

void StringCount( char *s );

int main()
{
    char s[MAXS];

    gets(s);
    StringCount(s);

    return 0;
}


void StringCount( char *s )
{
    int a=0,b=0,c=0,d=0,e=0,i;


    for(i=0;*s!=0;s++)//'\0'的ASCII码是0，即表示不是空字符
    {
        if(*s>='A'&&*s<='Z')
            a++;
        else if(*s>='a'&&*s<='z')
            b++;

        else if(*s==' ')
            c++;
        else if(*s>='0'&&*s<='9')
            d++;
        else
            e++;


    }

    printf("%d %d %d %d %d",a,b,c,d,e);

}
