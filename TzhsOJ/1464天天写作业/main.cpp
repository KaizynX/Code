#include <iostream>
#include <cstdio>
#include <cmath>
#define LL long long
using namespace std;
const int maxa=1000000000+5;
const int maxd=100000+5;
bool sushu[maxd];
LL a,b;

bool pd(LL a)
{
    for(int i=2;i<=sqrt(a)+0.05;++i)
    {
        if(a%i==0)return 0;
    }
    return 1;
}

int main()
{
    int i,j,ans=0;
    scanf("%lld%lld",&a,&b);
    for(i=a;i<=b;++i)
    {
        if(pd(i))ans++;
    }
    printf("%d",ans);
    return 0;
}
//999900000 1000000000
//TLE
