#include <stdio.h>
#include <stdlib.h>

int main()
{
   int low,high,mid,m,n,y[20],i,j,count=0,search=0,s,flag=0;

   scanf("%d",&n);

   for(i=0;i<n;i++)
   {
       scanf("%d",&y[i]);

   }

   scanf("%d",&m);

   low=0;high=n-1;i=0;

   while(low<=high)
   {
       search++;

       mid=(high+low)/2;

       if(y[mid]==m)
       {
           count++;
           flag=1;
           break;


       }

       else if(y[mid]<m)
        low=mid+1;
       else
        high=mid-1;


   }      //找到一个后向两边，因为是单调数列

   for(i=mid-1;i>=0;i--)
    {
        if(y[i]==m)
        count++;

    }

    s=mid-count+1;   //总共统计完之后算s

    for(i=mid+1;i<n;i++)
    {
        if(y[i]==m)
        count++;


    }

    if(flag==1)
    {
         printf("查找次数%d\n",search);

        for(i=0;i<count;i++)
            printf("位置:%d\n",s+i);
    }

    else
        printf("not found");





    return 0;
}
