#include <stdio.h>
#include <stdlib.h>

int main()
{
   int start,end,t,a,b,m,h;

   scanf("%d %d",&start,&t);

   h=start/100;
   m=start%100;


   a=h*60+m;
   b=a+t;

   end=b/60*100+b%60;

   printf("%03d\n",end);

   return 0;

}
