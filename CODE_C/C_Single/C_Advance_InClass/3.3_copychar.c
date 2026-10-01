#include <stdio.h>

int main()
{
    char a[] = "It is a dog.", b[20];
    int i = 0;

    do
    {
        *(b + i) = *(a + i);
        i++;
    } while (*(a + i) != '\0'); // 也可以写成while(*(a+i))

    puts(b);
}