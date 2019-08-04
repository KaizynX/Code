#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e5+7;

int n, m, k;
int a[Maxn];
long long s[Maxn], tr[Maxn];
long long res = 0;

inline void add(int i, int k)
{
    for( ; i <= n; i += i & -i) tr[i] += k;
}

inline long long query(int x)
{
    long long res = 0;
    for( ; x; x -= x & -x) res += tr[x];
    return res;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        tr[i] = tr[i-1]+a[i];
    }
    for(int i = 0; i < m; ++i)
    {
        long long minv = 0, cur, b = 0;
        for(int j = 1; j <= n; ++j)
        {
            if(b%m == i) b -= k;
            cur = b+s[j];
            res = max(res, cur-minv);
            minv = min(minv, cur);
        }
        /*
        for(int j = 1; j <= n; ++j)
            if(j%m == i) add(j, k);
        */
    }
    cout << res << endl;
    return 0;
}
