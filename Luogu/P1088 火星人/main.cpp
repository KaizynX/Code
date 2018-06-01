#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int maxn=10000+5;
const int maxm=100+5;

int n,m,t;
int a[maxn],b[maxn];
bool vis[maxn];

inline void print()
{
    for(int i=1;i<n;++i)
    {
        printf("%d ",b[i]);
    }
    printf("%d\n",b[n]);
}

void dfs(int cur)
{
    if(cur>n)
    {
        t++;
        if(t>m)
        {
            print();
            exit(0);
        }
        return;
    }

    else
    {
        for(int i=1;i<=n;++i)
        {
            if(t==0)i=a[cur];
            if(vis[i]==1)continue;
            vis[i]=1;
            b[cur]=i;
            dfs(cur+1);
            vis[i]=0;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",a+i);
    }
    dfs(1);
    return 0;
}
