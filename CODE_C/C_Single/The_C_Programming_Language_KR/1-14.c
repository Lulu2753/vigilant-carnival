#include <stdio.h>
#include <ctype.h>  //isprint()函数

#define MAXCHAR 128
#define MAXHIST 50

int main()
{
    int c, i, len, maxvalue = 0;
    int cc[MAXCHAR];

    for(i = 0; i < MAXCHAR; ++i)
        cc[i] = 0;
    
    while((c = getchar()) != EOF)
        if(c < MAXCHAR)
            ++cc[c];   //用ASCII码代替，相当于会罗列所有常用符号

    for(i = 0; i < MAXCHAR && i != 32; ++i)
    {
        if(cc[i] > maxvalue)
            maxvalue = cc[i];
    }
        
    for(i = 0; i < MAXCHAR; ++i)
    {
        //if(isprint(i))  用来判断字符是否可显示，比如tab换行就不会显示，空格会显示一个空的
        if(cc[i] > 0 && isprint(i) > 0  && i != ' ')   //空格太多，忽略空格
        {
            printf("%c - %2d : ", i, cc[i]);

            /*防止星号太多*/
            if(cc[i] > 0)
            {
                //if(len = cc[i] * MAXHIST / maxvalue < 0)    //包括赋值的动作，<优先级高于=，所以其实赋的是0（假值）
                    //len = 1;
                
                len = cc[i] * MAXHIST / maxvalue;

                if(len == 0)
                    len = 1;  //否则1的时候没打出星号
            }

            else
                len = 0;
            /*以上*/

            //int len = cc[i];   字符数少可以直接用这个
            while(len > 0)
            {
                putchar('*');
                --len;
            }
            putchar('\n');
        } 
        
        else
            continue;
        
    }
        
}