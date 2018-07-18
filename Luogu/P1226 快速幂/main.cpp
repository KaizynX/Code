//http://blog.csdn.net/ltyqljhwcm/article/details/53043646
#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;

LL quick(LL a,LL b,LL c)
{
    LL ans=1;
    a%=c;
    while(b!=0)
    {
        if(b&1)
            ans=(ans*a)%c;
        b>>=1;
        a=(a*a)%c;
    }
    return ans;
}

inline void print(LL a,LL b,LL c,LL ans)
{
    printf("%lld^%lld mod %lld=%lld\n",a,b,c,ans);
}

int main()
{
    LL a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    print(a,b,c,quick(a,b,c));
    return 0;
}
