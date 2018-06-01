#include <iostream>
#include <cstdio>
using namespace std;
int n,k,ans;

void bfs(int cur,int rest,int last)
{
	if(cur==k)
	{
		if(rest>=last)
			ans++;
		return;
	}
	for(int i=last;i<=rest;++i)
		bfs(cur+1,rest-i,i);
}

int main()
{
	scanf("%d%d",&n,&k);
	bfs(1,n,1);
	printf("%d\n",ans);
	return 0;
}
