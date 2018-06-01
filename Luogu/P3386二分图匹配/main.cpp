#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn=1005;
int N,M,E,ans,f[maxn];
bool e[maxn][maxn],vis[maxn];

bool hungarian(int i)
{
    for(int j=1;j<=M;++j)
    {
        if(e[i][j]&&!vis[j])
        {
            vis[j]=1;
            if(!f[j]||hungarian(f[j]))
            {
                f[j]=i;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int i,u,v;
    scanf("%d%d%d",&N,&M,&E);
    for(i=1;i<=E;++i)
    {
        scanf("%d%d",&u,&v);
        e[u][v]=1;
    }
    for(i=1;i<=N;++i)
    {
        memset(vis,0,sizeof vis);
        if(hungarian(i))
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}
