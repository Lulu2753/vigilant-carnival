#include <stdio.h>
#include <stdlib.h>

int main()
{
   int Tom=0,Jerry=0,Spike=0,Invalid=0,i;

   while(1)
   {
       scanf("%d",&i);

       if(i==1)
        Tom++;
       if(i==2)
        Jerry++;
       if(i==3)
        Spike++;
       if(i==0||i==4)
        Invalid++;

       if(i==-1)
        break;

   }

   if(Tom>Invalid||Jerry>Invalid||Spike>Invalid&&(Tom+Jerry+Spike+Invalid!=0))
    printf("Tom = %d Jerry = %d Spike = %d Invalid = %d\n",Tom,Jerry,Spike,Invalid);
    else

     {
        printf("Tom = %d Jerry = %d Spike = %d Invalid = %d\n",Tom,Jerry,Spike,Invalid);
        printf("Election invalid!\n");
     }


    return 0;
}
