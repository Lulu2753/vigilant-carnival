#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int i, cnt, lastc, c, state;

    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
            {
                cnt = 0;
                state = OUT;
            }
        else
            ++cnt;

        if(state = IN)

    }

    
}