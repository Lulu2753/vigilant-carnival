#include <stdio.h>
#include <stdlib.h>

int main()
{
   int mm,yy,dd;

   scanf("%d-%d-%d",&mm,&dd,&yy);

   printf("%d-%02d-%02d",yy,mm,dd);

   return 0;

}
