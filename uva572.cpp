#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 107;
const int dx[] = {0,0,1,-1,-1,1,-1,1};
const int dy[] = {1,-1,0,0,-1,-1,1,1};

int n, m ,ans;
bool a[Maxn][Maxn], vis[Maxn][Maxn];

void dfs(int x, int y)
{
	if(!a[x][y] || vis[x][y]) return;
	vis[x][y] = true;
	for(int d = 0; d < 8; ++d) dfs(x+dx[d],y+dy[d]);
}

int main()
{
	char c;
	while(scanf("%d%d",&n,&m) && n && m)
	{
		ans = 0;
		memset(vis,0,sizeof vis);
		memset(a,0,sizeof a);
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
			{
				cin >> c;
				if(c == '@') a[i][j] = true;
				else a[i][j] = false;
			}
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= m; ++j)
			{
				if(vis[i][j] || !a[i][j]) continue;
				dfs(i,j);
				++ans;
			}
		printf("%d\n",ans);
	}
	return 0;
}
