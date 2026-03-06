#include <stdio.h>

#define MAXHIST 15       //max length of histogram直方图
#define MAXWORD 11       //max length of a word
#define IN 1
#define OUT 0

/*记录每个长度的单词有多少个，并把相对个数用直方图表示出来*/

int main()
{
    int c,i, nc, state;
    int len;           //length of each bar
    int maxvalue;      //maximum value for wl[]
    int ovflow;         //number of overflow words
    int wl[MAXWORD];   //word length counters，记录每个单词

    state = OUT;
    nc = 0;
    ovflow = 0;

    for(i = 0; i < MAXWORD; ++i)
        wl[i] = 0;
    
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
            if(nc > 0)
                if(nc < MAXWORD)
                    ++wl[nc];
                else
                    ++ovflow;    //处理超出长度的，仍要算进去，后面扩大max范围
            nc = 0;
        }

        else if(state == OUT)
        {
            state = IN;
            nc = 1;     //新词
        }
        else
            ++nc;
    }

    //设置最大值
    maxvalue = 0;

    for(i = 1; i < MAXWORD; ++i)
        if(wl[i] > maxvalue)
            maxvalue = wl[i];

    for(i = 1; i < MAXWORD; ++i)
        {
            printf("%5d - %5d : ", i, wl[i]);
            if(wl[i] > 0)
            {
                if((len = wl[i] * MAXHIST / maxvalue) <= 0)   //表现相对多少
                    len = 1;
            }
            else
                    len = 0;
                while (len > 0)
                {
                    putchar('*');
                    --len;
                }
                putchar('\n');
        }

    if(ovflow > 0)
        printf("There are %d words >= %d\n", ovflow, MAXWORD);


}