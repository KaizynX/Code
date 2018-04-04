#include <iostream>
#include <cstdio>
using namespace std;
const int N=10+3;
int n,r,a[N];
bool vis[N];

void print()
{
	for(int i=1;i<=r;++i)
		printf("%3d",a[i]);
	printf("\n");
}

void bfs(int cur)
{
	if(cur>r)
	{
		print();
		return;
	}
	for(int i=1;i<=n;++i)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			a[cur]=i;
			bfs(cur+1);
			vis[i]=0;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&r);
	bfs(1);
	return 0;
}
