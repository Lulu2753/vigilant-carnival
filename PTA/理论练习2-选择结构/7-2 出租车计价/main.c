#include <stdio.h>
#include <stdlib.h>

int main()
{
    float s=0,m=0;
    int t=0;

    scanf("%f %d",&s,&t);  //scanf不可设置精度，可设置域宽如%2f，即前面补的空格

        if (s<=3)
            m=10+t/5*2;
        if (3<s&&s<=10)
            m=10+2*(s-3)+t/5*2;
        if (s>10)
            m=10+2*7+3*(s-10)+t/5*2;




    printf("%.0f",m);

    return 0;
}
