#include <stdio.h>
#include <stdlib.h>

int main()
{

  int i,s,n;

    scanf("%d",&n);
    s=0;
    for( i=1; i<n; i++ )
    {
        if(n%i==0)  //判断i是否是n的因子
        s=s+i; //计算真因子之和
    }
    if(n==s)
        printf("是完全数");
    else
        printf("不是完全数");
    return 0;
}
