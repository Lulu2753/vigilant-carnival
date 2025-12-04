#include <stdio.h>

int main()
{
	int i, j;
	char ttt[3][3];
	char whowin = '.';

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			ttt[i][j] = getchar();
		getchar();
	}

	for (i = 0; i < 3; i++)
	{
		if (ttt[0][i] == ttt[1][i] && ttt[1][i] == ttt[2][i])
			whowin = ttt[0][i];

		if (ttt[i][0] == ttt[i][1] && ttt[i][1] == ttt[i][2])
			whowin = ttt[i][0];
	}

	//已经有胜负，但是再下的就判断不了，因为whowin会重复，除非用标记

	if (ttt[0][0] == ttt[1][1] && ttt[1][1] == ttt[2][2])
		whowin = ttt[0][0];

	if (ttt[0][2] == ttt[1][1] && ttt[1][1] == ttt[2][0])
		whowin = ttt[1][1];

	if (whowin == 'O')
		printf("O win!");
	else if (whowin == 'X') // 大写X
		printf("X win!");
	else
		printf("No one win!");

	return 0;
}