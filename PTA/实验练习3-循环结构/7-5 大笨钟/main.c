#include <stdio.h>
#include <stdlib.h>

int main()
{
    int hh,mm,i=1;


   scanf("%d:%d",&hh,&mm);

   if((0<=hh&&hh<=11)||(hh==12&&mm==00))
    printf("Only %02d:%02d.  Too early to Dang.",hh,mm);

   else
   {
       if(mm==00)
        while(1)
       {
           if(i>hh-12)
           break;


           printf("Dang");
           i++;

       }

       else
        while(1)
       {
           if(i>hh+1-12)
            break;

           printf("Dang");
           i++;


       }
   }

   return 0;
}
