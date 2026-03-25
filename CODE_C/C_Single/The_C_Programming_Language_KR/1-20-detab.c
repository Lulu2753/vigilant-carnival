#include <stdio.h>

#define TAB 8

int main()
{
    int pos, c, nb;   //position, number of blank

    nb = 0;
    pos = 0;   //最开始定为0

    while((c=getchar()) != EOF)
    {
        if(c=='\t')
        {
            nb = TAB - pos % TAB;
            while(nb > 0)
            {
                putchar(' ');
                ++pos;
                --nb;
            }
        }

        else if(c == '\n')
        {
            putchar(c);
            pos = 0;
        }

        else
        {
            putchar(c);
            ++pos;   //有一个字就加一个
        }

    }
}