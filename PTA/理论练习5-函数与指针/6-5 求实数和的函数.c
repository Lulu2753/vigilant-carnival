#include <stdio.h>
#define MAXN 10

float sum(float  data[], int N);

int main()
{
    int  n, i;
    float data[MAXN];
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%f", &data[i]);
    printf("%.2f\n", sum(data, n));
    return 0;
}

float sum(float data[], int N)
{
    float sum = 0;
    int i;

    for (i = 0; i < N; i++)
    {
        sum += data[i];
    }

    return sum;
}