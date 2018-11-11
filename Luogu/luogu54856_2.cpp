#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 307;

long long ans;
int n;
int h[Maxn];

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", h+i);
    sort(h, h+n+1);
    for(int i = 0, l = 0, r = n; i <= n; (++i)&1 ? l++ : r--)
        ans += (h[l]-h[r])*(h[l]-h[r]);
    printf("%lld\n", ans);
    return 0;
}
