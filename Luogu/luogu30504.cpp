#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int Maxn = 507;
const int Maxc = 20;

int R, C, N;
bool m[Maxn][Maxn];
char cot[Maxn];

int main()
{
	char c;
	cin >> R >> C >> N;
	for(int i = 1; i <= R; ++i)
		for(int j = 1; j <= C; ++j)
		{
			cin >> c;
			if(c == '.') m[i][j] = true;
			else if(c == '*') m[i][j] = false;
			else
			{
				m[i][j] = true;
				if(c == 'A');
			}
		}
	return 0;
}
