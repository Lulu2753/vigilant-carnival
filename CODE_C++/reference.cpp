#include <iostream>
using namespace std;

int main()
{
    int someInt;         // 需要事先声明或定义
    int &rInt = someInt; // rInt是someInt的引用，rInt是别名
    // 不会专门为rInt分配内存
    // 对引用的改动实际是对目标的改动【同时改动】rInt和someInt指向同一个内存地址

    someInt = 6;
    printf("someInt:%d\n", someInt);
    printf("rInt:%d\n", rInt);

    rInt = 8;
    cout << "someInt:" << someInt << endl;
    cout << "rInt:" << rInt << endl;

    system("pause");

    return 0;
}