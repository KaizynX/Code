#include <iostream>
#include <cstdio>
#define LL long long
#define mo 10007
using namespace std;

const int Maxn = 10000+5;

int T;
LL x,y;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&x,&y);
        printf("%lld\n",(x%mo)*(y%mo)%mo);
    }
    return 0;
}
