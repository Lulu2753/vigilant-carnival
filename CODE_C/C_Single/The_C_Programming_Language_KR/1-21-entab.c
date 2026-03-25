#include <stdio.h>

#define TAB 8

int main()
{
    int c, pos, nt, nb;

    nb = 0;
    nt = 0;
    pos = 0;

    while((c = getchar()) != EOF)
    {
        ++pos;

        if(c == ' ')
        {
            if(pos % TAB != 0)
                ++nb;
            else 
            {
                nb = 0;  //归零
                ++nt;
            }
        }
        else
        {
            for(; nt > 0; --nt)
                putchar('\t');
            
            if(c == '\t')
                nb = 0;
            else
            {
                for(; nb > 0; --nb)
                    putchar(' ');
            }

            putchar(c);

            if(c == '\n')
                pos = 0;
            else if(c == '\t')
                pos = pos + (TAB - pos % TAB);
        }
   

    }
}