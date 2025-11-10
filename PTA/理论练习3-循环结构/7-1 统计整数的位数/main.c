#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n,i=0;
    scanf("%d",&n);

if(n!=0)
{
   while(n!=0)
    {
        n/=10;
        i++;

    }

    printf("It contains %d digits.\n",i);
}

else
    printf("It contains 1 digits.\n");




    return 0;

}
