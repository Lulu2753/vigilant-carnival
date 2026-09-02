#include <stdio.h>

int main()
{
    float rate1, rate2;
    float initial, final;

    rate1 = 0.0110;
    rate2 = 0.0155;

    scanf("%f", &initial);

    // 一年，存本取息
    printf("一年，存本取息: %.2f\n", initial * rate1 * 3);

    // 一年，复利
    final = initial;
    for (int i = 0; i < 3; i++)
    {
        final *= (1 + rate1);
    }

    printf("一年，复利: %.2f\n", final - initial);

    // 三年
    printf("三年，存本取息: %.2f\n", initial * rate2 * 3);

    return 0;
}