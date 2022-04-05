/***************************************************
 *					Problem 592A				   *
 * https://codeforces.com/problemset/problem/592/A *
 ***************************************************/

#include <iostream>

int main()
{
	//Only one test case per test
	char Board[8][8];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			std::cin >> Board[i][j];
		}
	}
	//We are guarenteed that every board configuration is solvable
	unsigned char stepsWhite = 0;
	bool isWhiteSolved = false;
	for (unsigned char i = 1; i < 8; ++i)
	{
		for (unsigned char j = 0; j < 8; ++j)
		{
			if (Board[i][j] != 'W') continue;
			bool isValid = true;
			for (unsigned char k = 0; k < i; ++k)
			{
				if (Board[k][j] == 'B')
				{
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				stepsWhite = i;
				isWhiteSolved = true;
				break;
			}
		}
		if (isWhiteSolved) break;
	}

	unsigned char stepsBlack = 0;
	bool isBlackSolved = false;
	for (signed char i = 6; i >= 0; --i)
	{
		for (signed char j = 0; j < 8; ++j)
		{
			if (Board[i][j] != 'B') continue;
			bool isValid = true;
			for (signed char k = 8; k > i; --k)
			{
				if (Board[k][j] == 'W')
				{
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				stepsBlack = 7 - i;
				isBlackSolved = true;
				break;
			}
		}
		if (isBlackSolved) break;
	}

	std::cout << (stepsBlack < stepsWhite ? "B" : "A");
	return 0;
}