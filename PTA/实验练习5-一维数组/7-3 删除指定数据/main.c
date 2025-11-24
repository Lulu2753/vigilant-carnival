#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[1000],m,i,j,del=0,flag=0;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    scanf("%d",&m);

    for(i=0;i<n-del;i++)
    {
        if(a[i]==m)
        {
            for(j=i;j<n-del;j++)
                a[j]=a[j+1];


            del++;

            for(j=0;j<n-del;j++)     //i内部就不能用i循环
                printf("%d ",a[j]);

            printf("\n");

            i--;

            flag=1;


        }



    }


    if(flag==0)
    {
        for(i=0;i<n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }





    return 0;
}
