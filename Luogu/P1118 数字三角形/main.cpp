#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
const int maxn=12+2;

int n,sum,k[maxn][maxn],a[maxn];
bool use[maxn];

inline void print()
{
    for(int i=1;i<=n;++i)
        printf("%d ",a[i]);
    printf("\n");
}

inline int cul()
{
    int res=0;
    for(int i=1;i<=n;++i)
    {
        res+=a[i]*k[n][i];
    }
    return res;
}

inline void pd()
{
    int res=cul();
    if(res==sum)
    {
        print();
        exit(0);
    }
}

void bfs(int cur)
{
    if(n%2==0 && cur>n/2)
    {
        pd();
        return;
    }
    else if(n%2==1 && cur>=n/2+1)
    {
        for(int i=1;i<=n;++i)
        {
            if(use[i])continue;
            a[cur]=i;
            pd();
        }
        return;
    }
    for(int i=1;i<n;++i)
    {
        if(use[i])continue;
        for(int j=n;j>i;--j)
        {
            if(use[j])continue;
            a[cur]=i;
            a[n-cur+1]=j;
            use[i]=1;
            use[j]=1;
            bfs(cur+1);
            use[i]=0;
            use[j]=0;
        }
    }
}

inline void init()
{
    k[1][1]=1;
    for(int i=2;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            k[i][j]=k[i-1][j-1]+k[i-1][j];
        }
    }
}

int main()
{
    scanf("%d%d",&n,&sum);
    init();
    bfs(1);
    return 0;
}
