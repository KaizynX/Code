#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxm=5000+5;

int n,m,ans;

struct farm
{
    int v,s;
    bool operator < (const farm a)const
    {
        return v<a.v;
    }
}a[maxm];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
        scanf("%d%d",&a[i].v,&a[i].s);
    sort(a+1,a+1+m);
    int cur=1;
    while(n>=a[cur].s)
    {
        n-=a[cur].s;
        ans+=a[cur].s*a[cur].v;
        cur++;
    }
    ans+=n*a[cur].v;
    printf("%d\n",ans);
    return 0;
}
