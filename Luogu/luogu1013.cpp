#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 20;

int n, v[128], vis[Maxn];
char m[Maxn][Maxn][2];

inline bool check()
{
	for(int i = 1, add1, add2, sum; i < n; ++i)
		for(int j = 1; j < n; ++j)
		{
			add1 = v[m[0][j][0]];
			add2 = v[m[i][0][0]];
			sum = m[i][j][1] ? v[m[i][j][0]]*(n-1)+v[m[i][j][1]] : v[m[i][j][0]];
#ifdef DEBUG
			printf("%d %d %d %d %d\n", i, j, add1, add2, sum);
#endif
			if(add1+add2 != sum) return false;
		}
	return true;
}

bool search(int cur)
{
	if(cur == n) return check();
	for(int i = 0; i < n; ++i)
	{
		if(vis[i]) continue;
		char now = m[0][cur][0];
		v[now] = i;
		vis[i] = 1;
		if(search(cur+1)) return true;
		vis[i] = 0;
	}
	return false;
}

int main()
{
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			scanf("%s", m[i][j]);
	if(!search(1)) puts("ERROR!");
	else
	{
		char now = m[0][1][0];
		printf("%c=%d", now, v[now]);
		for(int i = 2; i < n; ++i)
		{
			now = m[0][i][0];
			printf(" %c=%d", now, v[now]);
		}
		printf("\n%d\n", n-1);
	}
	return 0;
}
