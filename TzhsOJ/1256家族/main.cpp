#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=5000+5;

int n,m,p;
int f[maxn];

int ff(int s)
{
    if(f[s]!=s)
        f[s]=ff(f[s]);
    return f[s];
}

int main()
{
    int i,u,v,fu,fv;
    scanf("%d%d%d",&n,&m,&p);
    for(i=1;i<=n;++i)
        f[i]=i;
    for(i=1;i<=m;++i)
    {
        scanf("%d%d",&u,&v);
        fu=ff(u);
        fv=ff(v);
        if(fu==fv)continue;
        f[fu]=fv;
    }
    for(i=1;i<=p;++i)
    {
        scanf("%d%d",&u,&v);
        fu=ff(u);
        fv=ff(v);
        if(fu==fv)
            printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
