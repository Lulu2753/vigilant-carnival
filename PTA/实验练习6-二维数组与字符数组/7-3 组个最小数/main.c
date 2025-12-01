#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x[10],i,j,count=1;  //按顺序存放每个数字个数
   char str[51];

   for(i=0;i<10;i++)
    scanf("%d",&x[i]);

   for(i=1;i<10;i++)
   {
       if(x[i]>=1)
       {
           str[0]=i+'0';  //转换成字符，用ASCII码
           x[i]--;
           break;
       }
   }

   for(i=0;i<10;i++)
   {
       for(j=1;j<=x[i];j++)
       {
           str[count]=i+'0';
           count++;
       }

   }

   str[count]='\0';

   printf("%s",str);  //设置串尾标记



    return 0;
}
