#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#define DEBUG

using namespace std;

const int Maxn = 107;

int N, Q;
int cnt[Maxn], size[Maxn];
int a[Maxn][Maxn];
int f[Maxn][Maxn];

int dp(int cur, int q, int father)
{
	if(q == 0) return 0;
	// a[father][cur] need one
	if(q == 1) return a[father][cur];
	if(f[cur][q]) return f[cur][q];
	// it's the leaf, the q is waste, so it's must smaller, so the case it's ok
	if(cnt[cur] == 1) return a[father][cur];

	int son[2];
	for(int i = 1, tmp = 0; i <= N; ++i)
	{
		if(a[cur][i] != -1 && i != father)
			son[tmp++] = i;
		if(tmp > 2) break;
	}
#ifdef DEBUG
	putchar('\n');
	printf("%d %d\n", cur, q);
	printf("%d %d\n", son[0], son[1]);
#endif

	int res = 0;
	for(int i = 0; i <= q-1; ++i)
	{
		res = max(res, dp(son[0], i, cur) + dp(son[1], q-i-1, cur));
#ifdef DEBUG
		printf("%d %d\n", i, res);
#endif
	}
	return f[cur][q] = res + a[father][cur];
}

int main()
{
	// WARING!!! a[x][y] == 0!!!
	memset(a, -1, sizeof a);
	scanf("%d%d", &N, &Q);
	for(int i = 1, u, v, apple; i < N; ++i)
	{
		scanf("%d%d%d", &u, &v, &apple);
		++cnt[u]; ++cnt[v];
		a[u][v] = a[v][u] = apple;
	}
	// root has two edge
	// leaves have one
	// others have three
	int root = 0;
	for(int i = 1; i <= N; ++i)
		if(cnt[i] == 2)
		{
			root = i;
			break;
		}
	a[0][root] = 0;
	printf("%d\n", dp(root, Q+1, 0));
	return 0;
}
