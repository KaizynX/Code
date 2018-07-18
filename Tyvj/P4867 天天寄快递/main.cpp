#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
const int maxn=200005;
int n,m,s,k,maxt[maxn][2];
long long ans;
struct Node
{
    int e,t;
}a[maxn];
priority_queue <int>q;
int main()
{
    freopen("express.in","r",stdin);
    freopen("express.out","w",stdout);
    int i,cur;
    scanf("%d%d%d%d",&n,&m,&s,&k);
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&a[i].e,&a[i].t);
        if(a[i].t>maxt[a[i].e][0])
        {
            maxt[a[i].e][0]=a[i].t;
            maxt[a[i].e][1]=i;
        }
    }
    for(i=1;i<=n;++i)
    {
        if(maxt[i][0]<k)
        {
            printf("-23333333\n");
            return 0;
        }
        ans+=maxt[i][0]-2;
        a[maxt[i][1]].t=0;
        s--;
        if(s<0)
        {
            printf("-23333333\n");
            return 0;
        }
    }
    for(i=1;i<=m;++i)
        if(a[i].t>2)
            q.push(a[i].t);
    while(--s&&!q.empty())
    {
        ans+=q.top()-2;
        q.pop();
    }
    printf("%lld\n",ans);
    return 0;
}
