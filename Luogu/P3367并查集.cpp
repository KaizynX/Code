#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn=10005;
const int maxm=200005;
int n,m,f[maxn];
int ff(int son)
{
	int fa=son;
	if(son!=f[son])
		fa=ff(f[son]);
	f[son]=fa;
	return fa;
}
int main()
{
	int i,x,y,ope,fx,fy;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)
		f[i]=i;
	for(i=0;i<m;++i)
	{
		scanf("%d%d%d",&ope,&x,&y);
		if(ope==1)
		{
			fx=ff(x);
			fy=ff(y);
			if(fx!=fy)
				f[fx]=fy;
		}
		else if(ope==2)
		{
			fx=ff(x);
			fy=ff(y);
			if(fx==fy)
				printf("Y\n");
			else
				printf("N\n");
		}
	}
	return 0;
}

