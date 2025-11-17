#include <stdio.h>
#include <math.h>

// 判断素数的函数
int isPrime(int num) {           //括号里表示返回值
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;

    int limit = sqrt(num);      //只需检查到根号n
    for (int i = 3; i <= limit; i += 2)    //直接检查奇数i
    {    
        if (num % i == 0) {
            return 0;    //表示假
        }
    }
    return 1;      //表示真
}

int main() {
    int n;
    scanf("%d", &n);

    // 直接从2开始找最小的p
    for (int p = 2; p <= n / 2; p++) {
        if (isPrime(p)) {
            int q = n - p;
            if (isPrime(q)) {
                printf("%d = %d + %d", n, p, q);
                break;  // 找到就退出
            }
        }
    }

    return 0;
}