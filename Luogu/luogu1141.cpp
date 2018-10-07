#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1000 + 7;
const int dx[] = { 0, 0,-1, 1 };
const int dy[] = { 1,-1, 0, 0 };

int n, m;
bool a[Maxn][Maxn];
bool vis[Maxn][Maxn];
int ans[Maxn*Maxn];
int fa[Maxn*Maxn];

inline int getint(); // quick read
inline int cg(int x,int y) { return (x-1) * n + y; } // turn arr[][] to arr[]
inline void init(); // init the answer of the every point
int dfs(int x, int y ,int fx, int fy); // now point and the root point
inline int query(int x,int y) { return ans[ fa[cg(x,y)] ]; }; // query the answer 

int main()
{
	n = getint();
	m = getint();
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			char c;
			cin >> c;
			if(c == '1') a[i][j] = true;
			else a[i][j] = false;
		}
	}

	init();

	int x, y;
	for(int i = 0; i < m; ++i)
	{
		x = getint();
		y = getint();
		printf("%d\n",query(x,y));
	}
	return 0;
}

int dfs(int x,int y,int fx,int fy)
{
	// num shows how big the group is
	// 1 is it self
	int nexx,nexy,num = 1;
	vis[x][y] = true;
	fa[ cg(x,y) ] = cg(fx,fy);

	for(int i = 0; i < 4; ++i)
	{
		nexx = x + dx[i];
		nexy = y + dy[i];
		if(a[nexx][nexy] == a[x][y]) continue; // 0 <--> 1
		if(vis[nexx][nexy]) continue;
		if(nexx < 1 || nexx > n || nexy < 1 || nexy > n) continue; // out of range
		num += dfs(nexx,nexy,fx,fy);
	}

	return num;
}

inline void init()
{
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
		{
			if(!vis[i][j])
			{
				ans[ cg(i,j) ] = dfs(i,j,i,j);
			}
		}
	}
}

inline int getint()
{
	int res = 0;
	int c = getchar();
	while(c < '0' || c > '9')
		c = getchar();
	while(c >= '0' && c <= '9')
	{
		res = res * 10 + c - '0';
		c = getchar();
	}
	return res;
}
