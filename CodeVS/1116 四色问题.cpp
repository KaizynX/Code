#include <iostream>

using namespace std;
const int maxn=10;
int n,ans,col[maxn];
bool map[maxn][maxn];

void dfs(int x)
{
	if(x>n)
	{
		ans++;
		return;
	}
	int flag;
	for(int c=1;c<=4;++c)
	{
		flag=1;
		for(int i=1;i<=n;++i)
			if(map[x][i]&&c==col[i])
			{
				flag=0;
				break;
			}
		if(flag)
		{
			col[x]=c;
			dfs(x+1);
			col[x]=0;
		}	
	}
		
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			cin>>map[i][j];
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
