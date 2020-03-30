/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 13:57:31
 * @LastEditTime: 2020-03-26 13:59:15
 */
#include<bits/stdc++.h>
#define il inline
#define debug printf("%d %s\n",__LINE__,__FUNCTION__)
using namespace std;
const int N=1005,inf=233333333;
int n,m,s,t=520,dis[N],h[N],cnt=1,ans;
struct edge{
    int to,net,v;
}e[N*2];
il void add(int u,int v,int w)
{
    e[++cnt].to=v,e[cnt].net=h[u],e[cnt].v=w,h[u]=cnt;
    e[++cnt].to=u,e[cnt].net=h[v],e[cnt].v=0,h[v]=cnt;
}
il bool bfs()
{
    queue<int>q;
    memset(dis,-1,sizeof(dis));
    q.push(s),dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=h[u];i;i=e[i].net)
        if(dis[e[i].to]==-1&&e[i].v>0)dis[e[i].to]=dis[u]+1,q.push(e[i].to);
    }
    return dis[t]!=-1;
}
il int dfs(int u,int op)
{
    if(u==t)return op;
    int flow=0,used=0;
    for(int i=h[u];i;i=e[i].net)
    {
        int v=e[i].to;
        if(dis[v]==dis[u]+1&&e[i].v>0)
        {
            used=dfs(v,min(e[i].v,op));
            if(!used)continue;
            flow+=used,op-=used;
            e[i].v-=used,e[i^1].v+=used;
            if(!op)break;
        }
    }
    if(!flow)dis[u]=-1;
    return flow;
}
int main()
{
    scanf("%d%d",&m,&n);
    int w,tot=0,x;
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&w);tot+=w;
        add(s,i,w);
        while(getchar()==' '){scanf("%d",&x);add(i,x+m,inf);}
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&x),add(i+m,t,x);
    while(bfs()) {
        for (int i = 1; i <= n+m; ++i) cout << dis[i] << " \n"[i==n+m];
        ans+=dfs(s,inf);
    }
    for (int i = 1; i <= n+m; ++i) cout << dis[i] << " \n"[i==n+m];
    ans=tot-ans;
    for(int i=1;i<=m;i++)if(dis[i]!=-1)printf("%d ",i);printf("\n");
    for(int i=1;i<=n;i++)if(dis[i+m]!=-1)printf("%d ",i);printf("\n");
    printf("%d",ans);
    return 0;
}