#include <stdio.h>
#include <stdlib.h>

int main()
{
    int d;
    scanf("%d",&d);

    switch(d%5)
    {
    case 1:
    case 2:
    case 3:
        printf("Fishing in day %d",d);break;
    case 4:
    case 0:
        printf("Drying in day %d",d);break;
    }


    return 0;
}
