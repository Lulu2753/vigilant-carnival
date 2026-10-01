#include <stdio.h>
#define STR_LEN 80

char *Fun()
{
    char str[STR_LEN + 1];
    scanf("%s", str);

    return str;
}

int main()
{
    printf("%s", Fun());

    return 0;
}