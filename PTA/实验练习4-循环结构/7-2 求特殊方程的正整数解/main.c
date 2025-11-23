#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x,y,flag=0;

    scanf("%d",&n);

    for(x=1;x<=n;x++)
    {
        for(y=sqrt(n);y>0;y--)
        {
            if(x*x+y*y==n)
            {
                flag=1;

                if(x>y)
                    break;

                printf("%d %d\n",x,y);


            }
        }
    }

    if(flag==0)
        printf("No Solution");




    return 0;
}
