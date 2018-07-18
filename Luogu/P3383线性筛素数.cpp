#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=10000005;
int res,n,m,sushu[maxn],tot;
bool f[maxn];
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    f[1]=1;
    for(i=2;i<=n;++i)
    {
        if(!f[i])
            sushu[++tot]=i;
        for(j=1;j<=tot;++j)
        {
            if(i*sushu[j]>n)
                break;
            f[i*sushu[j]]=1;
            if(i%sushu[j]==0)
                break;
        }
    }
    for(i=0;i<m;++i)
    {
        scanf("%d",&res);
        if(f[res])
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
