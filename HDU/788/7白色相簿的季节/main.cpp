#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 18+5;

int T,n;

long long cp(int n)
{
    if(n==1)return 0;
    if(n==2)return 1;
    return (n-1)*(cp(n-1)+cp(n-2));
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%lld\n",cp(n));
    }
    return 0;
}
