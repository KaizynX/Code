#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 10000+5;
const int Maxm = 20000+5;
const int Maxe = 5000;

int n,m,ans;
int d[Maxn],e[Maxn][Maxe],p[Maxn],f[Maxn];
int q[Maxn],h,t;

int main()
{
	int i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)
	{
		scanf("%d%d",&a,&b);//a>b
		p[b]++;//入度b的数量
		e[b][ p[b] ]=a;
		d[a]++;//出度
	}
	for(i=1;i<=n;++i)
	{
		if(d[i]==0)
		{
			q[++t]=i;
		}
	}
	while(h<t)
	{
		h++;
		b=q[h];
		for(i=1;i<=p[b];++i)
		{
			a=e[b][i];
			d[a]--;
			if(d[a]==0)
			{
				q[++t]=a;
			}
			f[a]=max(f[a],f[b]+1);
		}
	}
	if(t<n)
	{
		printf("Poor Xed");
		return 0;
	}
	for(i=1;i<=n;++i)
	{
		ans+=f[i];
	}
	ans+=100*n;
	printf("%d",ans);
	return 0;
}
