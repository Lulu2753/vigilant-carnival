#include <stdio.h>

int main()
{
    char a[] = "It is a dog.", b[20];
    char *p1 = a, *p2 = b;
    int i = 0;

    do
    {
        *p2 = *p1;
        p2++; // 指针本身后移
        p1++;
    } while (*p1 != '\0');

    puts(b);

    return 0;
}