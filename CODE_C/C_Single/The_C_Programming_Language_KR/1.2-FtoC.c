#include <stdio.h>

int main()
{
    float fahr, celsius;
    int lower,upper,step;  //与float运算会转换为浮点数

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Celsius to Fahrenheit\n");

    while(fahr<=upper)
    {
        celsius = 5.0 * (fahr-32) / 9.0;  //整数除法是舍位，截断
        //printf("%d\t%d\n", fahr, celsius);
        printf("%3.0f %6.1f\n", fahr, celsius);   //以小数点为界，小数点后表示保留的小数位数，前面的表示总共占多少字宽
        fahr = fahr + step;
    }
}