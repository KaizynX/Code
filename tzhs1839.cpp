#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

const int Maxf = 1024 + 7;
const int Maxn = 500 + 7;

int n, maxn;
int cnt[Maxn];
stack<int> s; // save the answer
// there is not only one edge between two point
int a[Maxn][Maxn];
// int u[Maxf], v[Maxf], fir[Maxf], nex[Maxf];

void dfs(int cur)
{
#ifdef DEBUG
	cout << cur << " " << pos << endl;
#endif
	for(int i = 1; i <= maxn; ++i)
	{
		if(a[cur][i])
		{
			a[cur][i] --;
			a[i][cur] --;

			dfs(i);
		}
	}
	s.push(cur);
}

int main()
{
	int x, y, start_point;
	scanf("%d",&n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%d%d",&x,&y);
		a[x][y] ++;
		a[y][x] ++;
		++cnt[x];
		++cnt[y];
		// recite the biggest point appear in the case
		if(x > maxn) maxn = x;
		if(y > maxn) maxn = y;
	}

	// start from a point whose edge % 2 == 1
	start_point = 1;
	for(int i = 1; i <= maxn; ++i)
	{
		// the point whose edge % 2 == 1 must less than or equal to 2
		// choose the smaller one to start
		if(cnt[i] % 2) 
		{
			start_point = i;
			break;
		}
	}
	// we know if it's OuLaHuiLu , from any point can have a way
	dfs(start_point);
	while(!s.empty())
	{
		printf("%d\n",s.top());
		s.pop();
	}
	return 0;
}
