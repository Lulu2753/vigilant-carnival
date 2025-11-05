#include <stdio.h>

int main()
{
    int hour1, minute1;
    int hour2, minute2;

    scanf("%d:%d", &hour1, &minute1);
    scanf("%d:%d", &hour2, &minute2);

    int hd = hour2 - hour1;
     int md = minute2 - minute1;
     if ( md<0) {
         md = md+60

;
          hd = hd-1

;
     }
    printf("%d %d\n", hd, md);
    return 0;
}
