#include <stdio.h>


#define IN 1
#define OUT 0

int main()
{
    int i, c, state;

    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
            {
                state = OUT;
                printf("\n");   //循环内立即打印，所以回车就输出
            }
        // else if(state = OUT)
        //     {
        //         state =  IN;
        //         printf("*");
        //     }
        else
            printf("*");
    }

    
}