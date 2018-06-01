#include <iostream>
#include <cstdio>
using namespace std;
const int N=13+3;
int n,ans,m[N][N];

void queen(int x,int y,int v)
{
	int i;
	for(i=1;i<=n;++i)
	{
		m[x][i]+=v;
		m[i][y]+=v;
		if(x+i<=n&&y+i<=n)
			m[x+i][y+i]+=v;
		if(x-i>=1&&y-i>=1)
			m[x-i][y-i]+=v;
		if(x+i<=n&&y-i>=1)
			m[x+i][y-i]+=v;
		if(x-i>=1&&y+i<=n)
			m[x-i][y+i]+=v;
	}
}

void bfs(int cur)
{
	if(cur>n)
	{
		ans++;
		return;
	}
	for(int i=1;i<=n;++i)
		if(m[cur][i]==0)
		{
			queen(cur,i,1);
			bfs(cur+1);
			queen(cur,i,-1);
		}		
}

int main()
{
	scanf("%d",&n);
	bfs(1);
	printf("%d\n",ans);
	return 0;
}
