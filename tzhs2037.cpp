#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long 

using namespace std;

const int Maxn = 40+5;
const int Maxq = 2000000;

int N,K,n;
LL ans;
int a[Maxn],c[Maxq];
int mid,pc;
// a[] divide to a[1 to n/2]  a[n/2+1 to n]

void dfs1(int cur,int sum)
{
	if(sum>K)return;
	if(cur>mid)//cur > n/2
	{
		c[++pc]=sum;
		return;
	}
	dfs1(cur+1,sum); // choose a[cur] or not
	dfs1(cur+1,sum+a[cur]);
}

void dfs2(int cur ,int sum)
{
	if(sum>K)return;
	if(cur>n)
	{
		int pos=upper_bound(c+1,c+1+pc,K-sum)-(c+1);
		ans+=pos;
		return;
	}
	dfs2(cur+1,sum);
	dfs2(cur+1,sum+a[cur]);
}

int main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;++i)
	{
		scanf("%d",&a[++n]);
		if(a[n]>K)n--;
	}
	mid=n/2;
	dfs1(1,0);
	sort(c+1,c+1+pc);// greater
	dfs2(mid+1,0);
	printf("%lld",ans);
	return 0;
}
