#include <bits/stdc++.h>

using namespace std;

int T, n, m;

inline bool prime(long long x)
{
    if(x == 0 || x == 1) return false;
    for(int i = 2; 1ll*i*i <= x; ++i)
        if(x%i == 0) return false;
    return true;
}

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        int cnta = 0, cntb = 0;
        long long x, cal = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; ++i)
        {
            scanf("%lld", &x);
            if(x != 1) cal ^= x, cnta++;
        }
        for(int i = 1; i <= m; ++i)
        {
            scanf("%lld", &x);
            if(x != 1) cal ^= x, cntb++;
        }
        if(cnta-cntb == 1 && prime(cal)) puts("YES");
        else puts("NO");
    }
    return 0;
}
