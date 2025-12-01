#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   char jian[10][6]={"0 ","1,.?!","2ABC","3DEF","4GHI","5JKL","6MNO","7PQRS","8TUV","9WXYZ"};
   char s[501];

   int i,j;

   while(scanf("%s",s)==1)
   {

       i=s[0]-'0';
       j=(strlen(s)-1)%strlen(jian[i]);

       printf("%c",jian[i][j]);

       if(getchar()=='\n')
        break;
   }

    return 0;
}
