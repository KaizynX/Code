#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int Maxn = 1e+5 + 7;

int n;
int nex[Maxn];
int f[Maxn];
bool vis[Maxn];

int dfs(int cur)
{
	vis[cur] = true;
	if(!vis[ nex[cur] ]) 
		f[cur] += dfs( nex[cur] );
	return f[cur];
}

inline void init()
{
	memset(vis,0,sizeof vis);
	for(int i = 1; i <= n; ++i)
		f[i] = 1;
}

int main()
{
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d",nex+i);
	}
	for(int i = 1; i <= n; ++i)
	{
		init();
		printf("%d\n",dfs(i));
	}
	return 0;
}
