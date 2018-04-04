#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=10005;
const int maxm=500005;
const int maxl=2147483647;
int n,m,s,f[maxn],pos[maxn];
bool vis[maxn];

struct Node
{
	int x,y,v;
	bool operator < (const Node &b)const
	{
		return x<b.x;
	}
}r[maxm];
priority_queue <int,vector<int>,greater<int> >q;
void Dijkstra(int cur)
{
    int time=0,minn,minf=cur;
	while(time<n)
    {
        vis[cur]=1;
        minn=maxl;
        for(int i=pos[cur-1]+1;i<=pos[cur];++i)
        {
            if(vis[r[i].y])continue;
            if(f[cur]+r[i].v<f[r[i].y])
                f[r[i].y]=f[cur]+r[i].v;
        }
        for(int i=1;i<=n;++i)
        {
            if(vis[i])continue;
            if(f[i]<minn)
            {
                minn=f[i];
                minf=i;
            }
        }
        cur=minf;
        time++;
    }
}
int main()
{
	int i;
	scanf("%d%d%d",&n,&m,&s);
	for(i=1;i<=n;++i)
		f[i]=maxl;
	f[s]=0;
	for(i=1;i<=m;++i)
		scanf("%d%d%d",&r[i].x,&r[i].y,&r[i].v);
    sort(r+1,r+m+1);
	for(i=1;i<=m;++i)
		pos[r[i].x]=i;
	Dijkstra(s);
	for(i=1;i<=n;++i)
		printf("%d ",f[i]);
	printf("\n");
	return 0;
}
