#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));

    int n = 335;
    int s[335];

    for (int i = 0; i < n; i++)
    {
        s[i] = 31 + i;
    }

    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1); // 随机选一个位置与之交换
        int tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int g[11][31] = {0};

    int k = 0;

    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < days[(i + 9) % 12]; j++)
        {
            g[i][j] = s[k++];
        }
    }

    int width = 8 + 31 * 4;

    for (int i = 0; i < 11; i++)
    {
        int used = 5;
        int sum = 0;
        printf("%2d月 ", (i + 9) % 12 + 1);

        for (int j = 0; j < days[(i + 9) % 12]; j++)
        {
            printf("%4d", g[i][j]);
            sum += g[i][j];
            used += 4;
        }

        printf("%*s共%d", width - used, "", sum);

        printf("\n");
    }
}