#include <math.h>
#include <stdio.h>

double Avg(int N, int  data[]);
double StdDev(int N, int  data[]);

int main()
{

    int N, i, data[100];

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &data[i]);
    printf("Average = %.4f\n", Avg(N, data));
    printf("Standard Deviation = %.4f", StdDev(N, data));

    return 0;

}

double Avg(int N, int  data[])
{
    int  i;
    float sum = 0;

    for (i = 0; i < N; i++)
        sum += data[i];

    return sum / N * 1.0;
        
}

double StdDev(int N, int  data[])
{
    int  i;
    float sum = 0, ave;

    for (i = 0; i < N; i++)
        sum += (data[i] - Avg(N, data)) * (data[i] - Avg(N, data));

    ave = sqrt(sum / N);

    return ave;
}