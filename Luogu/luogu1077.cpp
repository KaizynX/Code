#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 107;
const int Mo = 1000007;

int n, m;
int a[Maxn];
int f[Maxn][Maxn];

int dfs(int cur, int rest)
{
	if(f[cur][rest]) return f[cur][rest] % Mo;
	if(cur >= n) return rest <= a[cur] ? 1 : 0;
	for(int i = 0; i <= a[cur] && rest-i >= 0; ++i)
	{
		f[cur][rest] = (f[cur][rest] + dfs(cur+1, rest-i)) % Mo;
	}
	return f[cur][rest] % Mo;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	printf("%d\n", dfs(1,m));
	return 0;
}
