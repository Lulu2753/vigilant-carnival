#include <stdio.h>

float celcius(float f);

int main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while(fahr <= upper)
    {
        printf("%3.0f %6.1f\n", fahr, celcius(fahr));  
        fahr = fahr + 20;
    }
}

float celcius(float f)
{
    return (5.0/9.0) * (f - 32);
}