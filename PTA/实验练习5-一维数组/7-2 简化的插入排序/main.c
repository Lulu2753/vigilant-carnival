#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,m[10],x,i,j;

   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
       scanf("%d",&m[i]);
   }

   scanf("%d",&x);

   for(i=0;i<n;i++)
   {
       if(x<=m[i])
       {
           for(j=n;j>i;j--)
           {
               m[j]=m[j-1];


           }


           break;


       }



   }

   m[i]=x;   //i为break执行时候的值




   for(i=0;i<=n;i++)
    printf("%d ",m[i]);

    return 0;
}
