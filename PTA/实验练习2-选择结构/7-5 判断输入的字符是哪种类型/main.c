#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    scanf("%c",&ch);

    if ('0'<=ch&&ch<='9')
        printf("This is a digit.");
    else if ('A'<=ch&&ch<='Z')
        printf("This is a capital letter.");
    else if ('a'<=ch&&ch<='z')
        printf("This is a small letter.");
    else
        printf("Other character.");



    return 0;
}
