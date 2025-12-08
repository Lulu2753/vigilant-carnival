#include <stdio.h>
#define MAXS 20

void f( char *p );


int main()
{
    char s[MAXS];

    gets(s);
    f(s);
    printf("%s\n", s);

    return 0;
}


void f( char *p )
{
    int l=0,i;
    char *start=p,*end=p;//保存起始位置
    char temp; //分两排


    while(*end!=0)
    {
        end++;    //要对应
    }   //此时已经到'\0'，而start不变

    end--;

        //p是内存地址，不能和0比较



    while(start<end)
    {
        temp = *start;
        *start = *end;
        *end = temp;



        start++;
        end--;

    }



}
