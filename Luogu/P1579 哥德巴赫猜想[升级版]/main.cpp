#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
const int maxn=20000+5;

int prime[maxn],pos,n;
bool p[maxn];

inline bool pd(int n)
{
    for(int i=2;i<=sqrt(n)+0.0005;++i)
    {
        if(n%i==0)return 0;
    }
    return 1;
}

inline void init()
{
    prime[++pos]=2;
    p[2]=1;
    for(int i=3;i<=maxn;++i)
    {
        if(pd(i))
        {
            prime[++pos]=i;
            p[i]=1;
        }
    }
}

inline void solve()
{
    int i,j,k;
    for(i=1;i<=pos;++i)
    {
        for(j=i;j<=pos;++j)
        {
            k=n-prime[i]-prime[j];
            if(k>=2 && p[k]==1)
            {
                printf("%d %d %d\n",prime[i],prime[j],k);
                exit(0);
            }
        }
    }
}

int main()
{
    scanf("%d",&n);
    init();
    solve();
    return 0;
}
