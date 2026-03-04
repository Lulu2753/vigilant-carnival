#include <stdio.h>

#define IN 1 //单词内
#define OUT 0 //单词外

int main()
{
    int c, nl, nw, nc, state;
    state = OUT;
    nl = nw = nc = 0;  //换行符定义新行，否则没有输入的时候也会有1行

    while((c = getchar()) != EOF)   //换行再Ctrl+Z同时按回车即可触发EOF!!
    {
        ++nc;
        if(c == '\n')
            ++nl;
        if(c == ' ' || c == '\n' || c == '\t')
            state = OUT;  //判断在不在单词外，只要在就是OUT
        else if(state == OUT)   //判断在的时候，只要前面是out，这时都会转换为in，本来是in的就不会管
        {
            state = IN;
            ++nw;
        }
    }

    printf("%d %d %d\n", nl, nw, nc);

}