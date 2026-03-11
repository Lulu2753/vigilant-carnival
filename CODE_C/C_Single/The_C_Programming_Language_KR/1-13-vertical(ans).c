#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXHIST 15
#define MAXWORD 11

int main()
{
    int c, i, j, nc, state;
    int wl[MAXWORD]; //每个长度的单词数!
    int maxvalue;    //最多单词数
    int ovflow;  //超出规定长度的单词数

    state = OUT;
    nc = 0;   //单词长度
    ovflow = 0;

    for(i = 0; i < MAXWORD; ++i)
        wl[i] = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n' || c == ' ' || c == '\t')
        {
            state = OUT;
            if(nc > 0)
            {
                if(nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;
                
                nc = 0;  //归零
            }
        }    
        else if(state == OUT)   //前提不是那几个空格
        {
            state = IN;
            nc = 1;  //新词
        }
        else 
            ++nc;
    }

    maxvalue = 0;   //与MAXWORD无关，只是单词数目的最大值

    for(i = 1; i < MAXWORD; ++i)   //从长度为1的单词开始算
    {
        if(wl[i] > maxvalue)
            maxvalue = wl[i];
    }

    for(i = MAXHIST; i > 0; --i)   //表示行数，永远一共15行，从上往下打印
    {
        for(j = 1; j < MAXWORD; ++j)   //从下往上数，判断
        {
            if(wl[j] * MAXHIST / maxvalue >= i)   //前面的比例是固定值，i在变化，i从最大值变小，达到定值就开始打印星号！！！
                printf(" * ");
            else
                printf("   ");
        }

        putchar('\n');
    }

    for(i = 1; i < MAXWORD; ++i)
        printf("%2d ", i);
    putchar('\n');
    for(i = 1; i < MAXWORD; ++i)
        printf("%2d ", wl[i]);
    putchar('\n');

    if(ovflow > 0)
        printf("There are %d words >= %d.\n", ovflow, MAXWORD);


}