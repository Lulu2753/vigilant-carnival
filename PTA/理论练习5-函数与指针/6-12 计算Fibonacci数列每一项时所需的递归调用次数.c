#include <stdio.h>

int count = 0;

long Fib(int a);

/* 你的代码将被嵌在这里 */

int main()
{
    int n, i, x;
    printf("Input n:");
    scanf_s("%d", &n);
    for (i = 1; i <= n; i++)
    {
        count = 0;       //计算下一项Fibonacci数列时将计数器count清零 
        x = Fib(i);
        printf("Fib(%d)=%d, count=%d\n", i, x, count);
    }
    return 0;
}

long Fib(int a)
{

    count++;//调用函数的次数，包括以下两种情况

    if (a <= 2)

        return 1;
    
       

    else
        return Fib(a - 1) + Fib(a - 2);
        

}