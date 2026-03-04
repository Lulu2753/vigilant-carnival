#include <stdio.h>

int main()
{
    long nc;  //int最大值32767

    nc = 0;
    while(getchar() != EOF)
        ++nc;
    printf("%ld\n", nc); //long对ld

    double cn;  //比long更大

    for(cn = 0; getchar() != EOF; ++cn)
        ;
    printf("%.0f\n", cn);

    //执行之前就会测试是否符合条件
}