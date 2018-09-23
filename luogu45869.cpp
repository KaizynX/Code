#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2e3+7;

int l, q;
char a[Maxn][Maxn];

int main()
{
	scanf("%d%d", &l, &q);
	for(int i = 1; i <= l; ++i)
		scanf("%s", a[i]+1);
	int x, y, res, tmp;
	while(q--)
	{
		scanf("%d%d", &x, &y);
		res = tmp = 1;
		for(int i = 1; i <= l; ++i)
		{
			if(x-i < 1 || x+i > l) break;
			if(a[x-i][y] != a[x+i][y]) break;
			tmp += 2;
		}
		res = max(res, tmp);
		tmp = 1;
		for(int i = 1; i <= l; ++i)
		{
			if(y-i < 1 || y+i > l) break;
			if(a[x][y-i] != a[x][y+i]) break;
			tmp += 2;
		}
		res = max(res, tmp);
		/*
		tmp = 1;
		for(int i = 1; i <= l; ++i)
		{
			if(x-i < 1 || x+i > l || y-i < 1 || y+i > l) break;
			if(a[x-i][y-i] != a[x+i][y+i]) break;
			tmp += 2;
		}
		res = max(res, tmp);
		tmp = 1;
		for(int i = 1; i <= l; ++i)
		{
			if(x-i < 1 || x+i > l || y-i < 1 || y+i > l) break;
			if(a[x+i][y-i] != a[x-i][y+i]) break;
			tmp += 2;
		}
		res = max(res, tmp);
		*/
		printf("%d\n", res);
	}
	return 0;
}
