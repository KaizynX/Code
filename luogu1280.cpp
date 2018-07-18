#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 10000+5;

int n,k;
int f[Maxn],sum[Maxn];
struct thing
{
	int p,t;
	bool operator < (const thing &b)const 
	{
		return p>b.p;
	}
}a[Maxn];

int main()
{
	int cur=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;++i)
	{
		scanf("%d%d",&a[i].p,&a[i].t);
		sum[ a[i].p ]++;
	}
	sort(a+1,a+k+1);
	for(int i=n;i>0;--i)
	{
		if(sum[i]==0)
		{
			f[i]=f[i+1]+1;
		}
		else
		{
			while(sum[i])
			{
				f[i]=max(f[i], f[ i+a[cur].t ] );
				cur++;
				sum[i]--;
			}
		}
	}
	printf("%d",f[1]);
	return 0;
}
