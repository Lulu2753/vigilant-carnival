#include <stdio.h>
#include <stdlib.h>

int main()
{
   int n,num,i=1,num1,s,s2,k=1;
   scanf("%d",&n);

   while(1)
   {
       scanf("%d",&num);

       i++;
       num1=num/1000;//在num变化前除

       s=0;
       s2=0; //在循环里面赋初值，否则第二个数在原来基础上累加

       while(k<=3)
       {
           s=s+num%10;
           num/=10;
           k++;

       }



       while (num1!=0)
       {

           s2=s2+num1%10;
           num1/=10;


       }


       if(s==s2)
        printf("You are lucky!\n");
       else
        printf("Wish you good luck.\n");


       if(i>n)
        break;


        k=1;



   }

    return 0;
}
