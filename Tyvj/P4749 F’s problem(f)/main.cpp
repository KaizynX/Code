#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
const int maxn=305;
const int maxm=5005;
int n,k,m,s,f[maxn],ans[3]={100000,1};
bool vis[maxn];
queue<int> q[maxn][2],p[2];

void build_road(int boss)
{
    vis[boss]=1;
    int nextb,nextv;
    queue <int> next;
    while(!q[boss][0].empty())
    {
        nextb=q[boss][0].front();
        nextv=q[boss][1].front();
        q[boss][0].pop();
        q[boss][1].pop();
        f[nextb]=min(f[boss]+nextv,f[nextb]);
        if(!vis[nextb])
            next.push(nextb);
    }
    while(!next.empty())
    {
        nextb=next.front();
        next.pop();
        build_road(nextb);
    }
}

bool cmp(int x,int y,int num)
{
    int nx=x*ans[1],ax=ans[0]*y;
    if(nx>ax)
        return 1;
    else if(nx==ax)
        return f[num]>f[ans[3]];
    else return 0;
}

int main()
{
    int i,a,b,c,x,v;
    scanf("%d%d%d",&n,&k,&m);
    for(i=0;i<m;++i)
    {
        scanf("%d%d%d",&a,&b,&c);
        q[a][0].push(b);
        q[a][1].push(c);
    }
    scanf("%d",&s);
    ans[2]=s;
    memset(f,1,sizeof f);//max
    f[s]=0;
    build_road(s);
    for(i=0;i<k;++i)
    {
        scanf("%d",&x);
        p[0].push(x);
    }
    for(i=0;i<k;++i)
    {
        scanf("%d",&v);
        p[1].push(v);
    }
    i=0;
    while(!p[0].empty())
    {
        i++;
        x=p[0].front();
        v=p[1].front();
        p[0].pop();
        p[1].pop();
        if(cmp(f[x],v,i))
        {
            ans[0]=f[x];
            ans[1]=v;
            ans[2]=i;
        }
    }
    printf("%d\n",ans[2]);
    return 0;
}
