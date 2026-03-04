#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, state;

    state = OUT; //初始化

    while((c = getchar()) != EOF)
    {
        //putchar(c); 这样会把空格算进去
        
        if(c == ' ' || c == '\n' || c == '\t')
        {
            if(state == IN)  //一定是第一个空格，不能把连续空格都算上，连续空格不会进入这些判断的putchar
            {
                state = OUT;
                putchar('\n');
            }
            
        }
        else if(state == OUT)
        {
            state = IN;
            putchar(c);
        }
        else
            putchar(c);
    }
}