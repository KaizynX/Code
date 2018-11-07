#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;

int n, maxa = INT_MIN;
int a[Maxn], mina[Maxn];
long long ans;

int main()
{
    scanf("%d", &n);
    mina[0] = INT_MAX;
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        mina[i] = min(mina[i-1], a[i]);
    }
    // mina[i] min[1, i]
    // maxa    max[i, n]
    ans = 1ll*a[2]-a[1];
    for(int i = n; i > 1; --i)
    {
        maxa = max(maxa, a[i]);
        ans = max(ans, 1ll*maxa-mina[i-1]);
    }
    printf("%lld\n", ans);
    return 0;
}
