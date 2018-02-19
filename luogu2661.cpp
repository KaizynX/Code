#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;
const int Maxn = 2*1e5+5;

int n,ans=Maxn;//最大的环=n
int a[Maxn],d[Maxn];
bool vis[Maxn];

void dfs(int point,int depth)
{
	if(a[point]==0)return;//退出循环
	if(vis[point] && depth>d[point])//找到环
	{
		ans=min(ans,depth-d[point]);
		a[point]=0;//删除该点,防止重复
		vis[point]=false;//同下
		return ;
	}

	vis[point]=true;//标记,找环
	d[point]=depth;//利用深度(时间戳?)求环的大小
	dfs(a[point],depth+1);
	a[point]=0;//删除该环有关的所有点
	vis[point]=false;//防止不小心找到环
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	//可能有多个环,遍历每个点
	for(int i=1;i<=n;++i)
	{
		dfs(i,1);
	}
	printf("%d\n",ans);
	return 0;
}
