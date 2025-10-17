#include <stdio.h>
const int M = 50;
const double N = 3.1415926;  //const后面要有分号，define不用有

int main()
{
	printf("%d\n", M);
	printf("%0.7f\n", N/2);  //%0.7f中的0可以省略，默认保留六位

	return 0;
}