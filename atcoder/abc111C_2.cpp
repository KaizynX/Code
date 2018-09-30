#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, maxv;
int v[2][Maxn], c[2][2];

int main()
{
	scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i)
	{
		scanf("%d", &a);
		v[i&1][a]++;
		maxv = max(maxv, a);
	}
	for(int i = 1; i <= maxv; ++i)
	{
		if(v[0][i] > v[0][c[0][0]]) c[0][0] = i;
		if(v[1][i] > v[1][c[1][0]]) c[1][0] = i;
	}
	if(c[0][0] != c[1][0])
	{
		printf("%d\n", n-v[0][c[0][0]]-v[1][c[1][0]]);
	}
	else
	{
		for(int i = 1; i <= maxv; ++i)
		{
			if(i != c[0][0] && v[0][i] > v[0][c[0][1]]) c[0][1] = i;
			if(i != c[1][0] && v[1][i] > v[1][c[1][1]]) c[1][1] = i;
		}
		// else c[][] = 0
		printf("%d\n", n-max(v[0][c[0][0]]+v[1][c[1][1]], v[0][c[0][1]]+v[1][c[1][0]]));
	}
	return 0;
}
