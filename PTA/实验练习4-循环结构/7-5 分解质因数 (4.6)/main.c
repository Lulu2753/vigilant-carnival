#include <stdio.h>
#include <stdlib.h>

int main()
{
   long n,i,j,count=0;


   scanf("%ld",&n);
   printf("%ld",n);


       for(j=2;j<=n;j++)
       {

           while(n%j==0)    //直接除，不用判断质数，因为2已经除完
           {

               n/=j;
               count++;

               if(count==1)
                printf("=%ld",j);
               else if(count!=1)
                printf("*%ld",j);

           }

       }




   if(count==0)
        printf("=%ld",n);


    return 0;
}
