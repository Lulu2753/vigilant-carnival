#include <stdio.h>

int CountDigit(int number, int digit);

int main()
{
    int number, digit;

    scanf_s("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}

int CountDigit(int number, int digit)
{
    int count = 0;
    
    if (number < 0)
        number *= -1;
    if (number == 0)
        return 1;

        while (number != 0)
        {
            

            if (number % 10 == digit)    //取余的结果与被除数相同，与除数无关！
                count++;

            number /= 10;
        }
    

    

    return count;
}