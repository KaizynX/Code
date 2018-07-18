#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define LL long long 
using namespace std;
const int Maxn = 200000;

int n,m,maxw,minw;
int w[Maxn+5],v[Maxn+5];
int sv[Maxn+5],sw[Maxn+5];
//前缀和 sv[n] v[0-n]的前缀和 fw[n] [0-n]满足w>W的数量
LL S,ans;
struct Q
{
	int l,r;
}q[Maxn+5];

inline void in();
inline LL cul(int W)
{
	LL now=0;
	int i,ql,qr;
	memset(sv,0,sizeof sv);
	memset(sw,0,sizeof sw);
	//前缀和
	for(i=1;i<=n;++i)
	{
		sw[i]=sw[i-1];
		sv[i]=sv[i-1];
		if(w[i]>=W)
		{
			sw[i]++;
			sv[i]+=v[i];
		}
	}
	for(i=1;i<=m;++i)
	{
		ql=q[i].l;
		qr=q[i].r;
		now+=(sw[qr]-sw[ql-1])*(sv[qr]-sv[ql-1]);
	}
	return now;
}

inline void solve()
{
	int l=minw,r=maxw,mid;
	LL now;
	ans=S;//W=maxw+1 now=0 ans=S
	while(l<=r)
	{
		mid=(l+r)/2;
		now=cul(mid);
		ans=min(ans,abs(S-now));
		if(S==now)//极其特殊情况
		{
			break;
		}
		else if(S>now)//mid 选大了
		{
			r=mid-1;
		}
		else if(S<now)//mid 选小了
		{
			l=mid+1;
		}
	}
	printf("%lld\n",ans);
}

int main()
{
	in();//输入
	solve();//二分找答案
	return 0;
}

inline void in()
{
	int i;
	scanf("%d%d%lld",&n,&m,&S);
	for(i=1;i<=n;++i)
	{
		scanf("%d%d",w+i,v+i);
		minw=min(minw,w[i]);
		maxw=max(maxw,w[i]);
	}
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
	}
}
