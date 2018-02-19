#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=200005;
int n,m,q,a[maxn];
bool f[maxn];
int main()
{
    freopen("stall.in","r",stdin);
    freopen("stall.out","w",stdout);
    int i,j,l,r,cur;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=m;++i)
        scanf("%d",a+i);
    for(i=0;i<q;++i)
    {
        scanf("%d%d",&l,&r);
        for(j=l;j<=r;++j)
            f[a[j]]=1;
        cur=0;
        for(j=1;j<=n;++j)
        {
            if(!f[j])cur++;
            else cur=0;
            if(cur==2)
            {
                printf("%d %d\n",j-1,j);
                break;
            }
        }
        if(cur!=2)
            printf("-1 -1\n");
        for(j=l;j<=r;++j)
            f[a[j]]=0;
    }
    return 0;
}
