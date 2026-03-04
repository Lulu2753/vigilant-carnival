#include <stdio.h>

int main()
{
    int fahr;

    printf("Adverse\n");

    for(fahr = 300; fahr >= 0; fahr = fahr - 20)
        printf("%3d %6.1f\n", fahr, (fahr-32)*(5.0/9.0));
   
    
}