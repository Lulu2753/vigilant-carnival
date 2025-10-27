#include <stdio.h>
#include <stdlib.h>

int main()
{
   int r1,r2;
   float R;


   scanf("%d %d",&r1,&r2);

   R=1.0/(1.0/r1+1.0/r2);

   printf("%.2f",R);






   return 0;
}
