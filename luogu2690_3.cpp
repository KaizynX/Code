#include <iostream>
#include <cstdio>

using namespace std;

const int Maxt = 1007;
const int Maxw = 40;

int T, W;
int a[Maxt];
int f[2][Maxw][Maxt];
// after w-1 move under tree 1|2

int main()
{
	scanf("%d%d", &T, &W);
	for(int i = 1; i <= T; ++i)
	{
		scanf("%d", a+i);
		f[0][0][i] = f[0][0][i-1];
		if(a[i] == 1) ++f[0][0][i];
	}
	for(int i = 1; i <= W; ++i)
		for(int j = i; j <= T; ++j)
		{
			f[0][i][j] = max(f[0][i][j-1], f[1][i-1][j-1]) + (a[j] == 1 ? 1 : 0);
			f[1][i][j] = max(f[1][i][j-1], f[0][i-1][j-1]) + (a[j] == 2 ? 1 : 0);
		}
	printf("%d\n", max(f[0][W][T], f[1][W][T]));
	return 0;
}

