#include <stdio.h>

int main()
{
    int space, tab, nl, c;

    space = tab = nl = 0;

    while((c = getchar()) != EOF)
        if(c == '\n')
            ++nl;
        if(c == '\t')
            ++tab;
        if(c == ' ')
            ++space;

    printf("%d %d %d\n", space, tab, nl);

}