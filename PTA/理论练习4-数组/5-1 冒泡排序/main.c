#include <stdio.h>
int  main()

{
    int  i, j, k, t, a[5] ;
    for (i = 0; i<5; i++)  scanf("%d",&a[i]);

    for (i = 0; i <=4; i++)
        {
            for (j = 0; j <= 3; j++)     //有j+1
            {
                if (a[j] > a[j + 1])

                {
                t = a[j];
                a[j] = a[j + 1];

                a[j+1]=t;


                }




            }


            for(k=0;k<5;k++)
                printf("%d ",a[k]);
            printf("\n");      //每比较一趟就输出一次


        }


    for (i = 0; i < 5; i++)
        printf("%d ", a[i]);

    return  0;
}
