#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 1e5+7;

int n, ans, x[Maxn];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a%b);
}

int main()
{
    scanf("%d%d", &n, x);
    for(int i = 1; i <= n; ++i)
        scanf("%d", x+i);
    sort(x, x+n+1);
    ans = x[1]-x[0];
    for(int i = 2; i <= n; ++i)
        ans = gcd(ans, x[i]-x[i-1]);
    printf("%d\n", ans);
    return 0;
}
