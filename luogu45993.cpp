#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e5+7;

int n, m, tot;
long long ans, a[Maxn<<1];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, x; i <= n; ++i)
    {
        scanf("%d", &x);
        a[++tot] = i-x;
        a[++tot] = i+x;
    }
    sort(a+1, a+1+tot);
    int cur = 1, cnt = 0;
    while(cur <= tot)
    {
        cnt = 0;
        while(cur+1 <= tot && a[cur+1] == a[cur])
        {
            ++cur;
            ++cnt;
        }
        ans += 1ll*cnt*(cnt+1)/2;
        ++cur;
    }
    printf("%lld\n", ans);
    return 0;
}
