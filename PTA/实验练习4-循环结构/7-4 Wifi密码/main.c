#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    char ch,tf,answers[100][4];

    scanf("%d",&n);
    getchar();

    for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=3;j++)

            {
            scanf("%c-%c",&ch,&tf);
            getchar();
            answers[i][j]=(tf=='T')?ch:0;
            }
    }

     for(i=0;i<=n-1;i++)
    {
        for(j=0;j<=3;j++)
        {
            if(answers[i][j]!=0)
            {
                  printf("%d",answers[i][j]-64);
                  break;
    }
            }
        }


    return 0;
}
