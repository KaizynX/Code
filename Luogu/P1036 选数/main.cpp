#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
const int maxn=20+5;
const int maxs=5000000*20;

long long ans;
int n,k,x[maxn];
bool p[maxs],v[maxs],u[maxn];

bool prime(int num)
{
    if(v[num])return p[num];
    v[num]=1;
    for(int i=2;i<=sqrt(num)+0.005;++i)
    {
        if(num%i==0)
        {
            p[num]=0;
            return 0;
        }
    }
    p[num]=1;
    return 1;
}

void solve(int cur,int sum,int last)
{
    if(cur>k)
    {
        if(prime(sum))
            ans++;
        return;
    }
    for(int i=last+1;i<=n;++i)
    {
        if(u[i])continue;
        u[i]=1;
        solve(cur+1,sum+x[i],i);
        u[i]=0;
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",x+i);
    solve(1,0,0);
    printf("%lld\n",ans);
    return 0;
}
