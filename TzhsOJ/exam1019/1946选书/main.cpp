#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=10000+5;

int n,a[maxn][2];
long long ans;
bool book[maxn];

void dfs(int cur)
{
    if(cur>n)
    {
        ans++;
        return;
    }

    for(int i=0;i<=1;++i)
    {
        if(book[a[cur][i]]==0)
        {
            book[a[cur][i]]=1;
            dfs(cur+1);
            book[a[cur][i]]=0;
        }
    }
}

int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;++i)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
