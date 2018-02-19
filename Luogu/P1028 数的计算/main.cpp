#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
const int maxn=1000+5;

LL a[maxn];

LL solve(int n)
{
    LL res=1;
    for(int i=1;i<=n/2;++i)
    {
        if(a[i])
            res+=a[i];
        else
            res+=solve(i);
    }
    a[n]=res;
    return res;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",solve(n));
    return 0;
}
