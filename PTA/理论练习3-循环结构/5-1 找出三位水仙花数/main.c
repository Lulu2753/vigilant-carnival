#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, t_num,digit,s;


    for (num = 100; num <= 999; num++){

            t_num=num;
            s = 0;

    do {
        digit = t_num % 10;
        s = s + digit * digit * digit;
        t_num = t_num / 10;
    }while (t_num != 0);



    if (s==num)
        {
        printf("%d\n", num);
    }
}

    return 0;
}
