#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word[5][80],t[80];   //t要定义成那么多的字符串
    int i,j;

    for(i=0;i<5;i++)
    {
        scanf("%s",word[i]);


    }

    for(i=0;i<4;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(strcmp(word[i],word[j])>0)
            {
                strcpy(t,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],t);


            }


        }


    }



    printf("After sorted:\n");

    for(i=0;i<5;i++)
        printf("%s\n",word[i]);





    return 0;
}
