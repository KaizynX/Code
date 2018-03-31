#include <cstdio>
#include <iostream>
#include <cstdlib>

using namespace std;

const int Maxf = 1024 + 7;
const int Maxn = 500 + 7;

int n, maxn;
int cnt[Maxn];
bool a[Maxn][Maxn], flag;

void dfs(int cur,int pos)
{
#ifdef DEBUG
	cout << cur << " " << pos << endl;
#endif
	printf("%d\n",cur);
	// we need n + 1 answer
	if(pos > n)
	{
		exit(0);
	}

	for(int i = 1; i <= maxn; ++i)
	{
		if(a[cur][i])
		{
			a[cur][i] = false;
			a[i][cur] = false;

			dfs(i,pos + 1);

			a[cur][i] = true;
			a[cur][i] = true;
		}
	}
}

int main()
{
	int x, y, start_point;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y] = a[y][x] = 1;
		++cnt[x];
		++cnt[y];
		// recite the biggest point appear in the case
		if(x > maxn) maxn = x;
		if(y > maxn) maxn = y;
	}

	// start from a point whose edge % 2 == 1
	start_point = Maxn;
	for(int i = 1; i <= maxn; ++i)
	{
		// the point whose edge % 2 == 1 must less than or equal to 2
		// choose the smaller one to start
#ifdef DEBUG
		cout << i << " " << cnt[i] << endl;
#endif
		if(cnt[i] % 2) 
			start_point = min(start_point, i);
	}
	// all point's edge % 2 == 0
	if(!start_point) start_point = 1;
#ifdef DEBUG
	cout << start_point << "\n" << endl;
#endif
	// we know if it's OuLaHuiLu , from any point can have a way
	dfs(start_point,1);
	return 0;
}
