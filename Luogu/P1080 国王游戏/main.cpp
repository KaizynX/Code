#include <iostream>
#include <cstdio>
#include <algorithm>
#define LL long long
using namespace std;
const int maxn=1000+5;
int n;
LL ans,p[maxn];
struct node
{
    LL a,b,c;
    bool operator <(const node d)const
    {
        return c<d.c;
    }
}m[maxn];

inline void in();

int main()
{
    in();
    p[0]=m[0].a;
    for(int i=1;i<=n;++i)
    {
        p[i]=p[i-1]*m[i].a;
        ans=max(ans,p[i-1]/m[i].b);
    }
    printf("%lld\n",ans);
    return 0;
}

inline void in()
{
    scanf("%d%lld%lld",&n,&m[0].a,&m[0].b);
    for(int i=1;i<=n;++i)
    {
        scanf("%lld%lld",&m[i].a,&m[i].b);
        m[i].c=m[i].a/m[i].b;
    }
    sort(m+1,m+n+1);
}
