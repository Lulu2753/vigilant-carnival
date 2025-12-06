#include<stdio.h>
int main()
{
    char s[100], alpha[] = { 'a', 'e', 'i', 'o', 'u' };
    int num[5] = { 0 };
    int i = 0, k;

    while ((s[i] = getchar()) != '\n')
        i++;

    s[i] = '\0';
    i = 0;

    while (s[i] != '\0')
    {
        for (k = 0; k < 5; k++)
            if (s[i] == alpha[k])
            {
                num[k]++;
                break; //不用比较后面的元音了 ，因为这个一旦匹配就一定是它，不break也行，只是徒增比较次数
            }
        i++;
    }

    for (k = 0; k < 5; k++)
        printf("%c:%d\n", alpha[k], num[k]);

    return 0;
}