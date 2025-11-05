#include <stdio.h>
#include <stdlib.h>

int main()
{
   int y,m,d,days=0;
   scanf("%d-%d-%d",&y,&m,&d);

   switch(m)
   {
   case 1:
    days=31;
   case 2:
    days+=28;
   case 3:
    days+=31;
   case 4:
    days+=30;
   case 5:
    days+=31;
   case 6:
    days+=30;
   case 7:
    days+=31;
   case 8:
    days+=31;
   case 9:
    days+=30;
   case 10:
    days+=31;
   case 11:
    days+=30;
   case 12:
    days+=31;

   }

   days=days-d;

   if (((y%4==0) && (y%100!=0) || (y%400==0))&& (m==1||m==2))
        printf("还有%d天到新年", days+2);
   else
        printf("还有%d天到新年", days+1);



    return 0;
}
