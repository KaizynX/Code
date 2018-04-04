#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 1e5+5;

int n,m,l,r,cnt,ans;
int f[Maxn];//Ç°×ººÍ

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&l,&r);
		f[l]--;
		f[r+1]++;
	}
	for(int i=0;i<=n;++i)
	{
		cnt+=f[i];
		ans+=(cnt<0 ? 0 : 1);
	}
	printf("%d",ans);
	return 0;
}
