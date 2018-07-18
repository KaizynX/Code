#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=105;
const int INF=0x7fffffff;
bool v[maxn];
int N,map[maxn][maxn],f[maxn][maxn];
long long Q;
void flyod(int r,int l)
{
	int minn=INF,minf=r;
	v[l]=1;
	for(int i=1;i<=N;++i)
	{
		if(v[i])continue;
		f[r][i]=min(f[r][i],f[r][l]+map[l][i]);
		if(f[r][i]<minn)
		{
			minn=f[r][i];
			minf=i;
		}
	}
	if(minf!=r)
		flyod(r,minf);
	v[l]=0;
}

int main()
{
	int i,j,a,b;
	scanf("%d",&N);
	for(i=1;i<=N;++i)
		for(j=1;j<=N;++j)
			scanf("%d",&map[i][j]);
    memcpy(f,map,sizeof map);
	for(i=1;i<=N;++i)
		flyod(i,i);
	scanf("%lld",&Q);
	for(i=0;i<Q;++i)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",f[a][b]);
	}
	return 0;
}
