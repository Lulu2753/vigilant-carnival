#include <stdio.h>

int main()
{
    float celcius, fahr;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 5;

    celcius = lower;

    printf("Celsiut to Fahrenheit\n");

    while(celcius<=upper)
    {
        fahr = celcius*9.0/5.0 + 32;
        printf("%3.0f %6.0f\n", celcius, fahr);
        celcius += step;
    }

}