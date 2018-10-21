#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int T, n, m, cnt[Maxn], tot;
long long a[Maxn];

inline bool prime(long long x)
{
    if(x == 1) return false;
    for(int i = 2; 1ll*i*i <= x; ++i)
        if(x%i == 0) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int flag = 1;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i) scanf("%lld", a+i);
        sort(a+1, a+n+1);
        // memset(cnt+1, cnt+n+1);
        tot = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(a[i] == a[i-1]) cnt[tot]++;
            else cnt[++tot] = 1;
        }
        n = unique(a+1, a+n+1)-(a+1);
        for(int i = 1, b; i <= m; ++i)
        {
            scanf("%lld", &b);
            cnt[lower_bound(a+1, a+n+1, b)-a]--;
        }

        int tmp = 0;
        long long num = 1;
        for(int i = 1; i <= n; ++i)
        {
            if(!cnt[i] || a[i] == 1) continue;
            if(cnt[i] == 1) ++tmp, num = a[i];
            if(cnt[i] >= 2 || tmp > 1)
            {
                flag = 0;
                break;
            }
        }
        puts(flag && prime(num) ? "YES" : "NO");
    }
    return 0;
}
