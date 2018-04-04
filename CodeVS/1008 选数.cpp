#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int N=20+3;
int n,k,a[N],ans;
bool vis[N];

bool pd(int num)
{
	int i=2;
	while(i<=sqrt(num)&&num%i!=0)
		i++;
	if(i>sqrt(num))
		return 1;
	else
		return 0;
}

void bfs(int cur,int v,int last)
{
	if(cur>k)
	{
		if(pd(v))
			ans++;
		return;
	}
	for(int i=last+1;i<=n;++i)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			bfs(cur+1,v+a[i],i);
			vis[i]=0;
		}
	}
}

int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+n); 
	bfs(1,0,0);
	printf("%d\n",ans);
	return 0;
}
