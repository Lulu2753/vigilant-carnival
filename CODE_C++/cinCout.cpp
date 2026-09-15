#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;                    // 输入，>>表示提取，输入给cin，cin是输入流
    cout << "\nx=" << x << endl; // 输出，<<表示插入，输出到cout，cout是输出流
    // \n是换行

    int num1, num2, num3;
    cin >> oct >> num1 >> dec >> num2 >> hex >> num3; // 连续输入多个数 //不用%d之类，自动识别
    // dec是十进制，oct八进制，hex十六进制，自动转换成这些进制
    // oct后面都是八进制
    cout << num1 << "\n"
         << num2 << "\n"
         << num3 << endl; // endl是c++独有的换行符，作用同\n

    system("pause");

    return 0;
}