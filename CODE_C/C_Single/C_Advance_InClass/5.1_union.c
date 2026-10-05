#include <stdio.h>

union data
{
    int m;
    float x;
    char *pc;
} value;

int main()
{
    char type;
    printf("type=");
    scanf("%c", &type);
    printf("\nthe size of the value:%d\n", sizeof(value));

    value.m = 4;
    value.x = 0.2;
    // value.pc = "ab";   //最后一次赋值才起作用

    if (type == 'i')
        printf("the value=%d\n", value.m);
    else if (type == 'f')
        printf("the value=%f\n", value.x);
    else if (type == 'c')
        printf("the value=%s\n", value.pc);
    else
        printf("error\n");

    return 0;
}