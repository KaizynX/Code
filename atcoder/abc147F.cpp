#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const long long INF = 1e18;

int x, d, n;
int a[N];
long long res;
vector<pair<long long, long long>> v;

inline int mod(int i) { return static_cast<int>(1ll*i*x%d); }
inline long long sum(int l, int r) { return l <= r ? 1ll*(l+r)*(r-l+1)/2 : 0; }
inline bool cmp (const int i, const int j) { return mod(i) < mod(j); }

inline void calc()
{
    if (!v.size()) return;
    sort(v.begin(), v.end());
    long long last = -INF;
    for (auto p : v) {
        long long l = p.first, r = p.second;
        res += max(0ll, r-max(l-1, last));
        last = max(last, r);
    }
}

int main()
{
    scanf("%d %d %d", &n, &x, &d);
    if (d == 0) {
        if (x == 0) return puts("1")&0;
        return printf("%d\n", n+1)&0;
    }
    if (d < 0) d = -d, x = -x;
    for (int i = 0; i <= n; ++i) a[i] = i;
    sort(a, a+n+1, cmp);
    long long xd, l, r;
    for (int i = 0; i <= n; ++i) {
        xd = 1ll*a[i]*x/d;
        l = xd+sum(0, a[i]-1);
        r = xd+sum(n-a[i], n-1);
        v.emplace_back(l, r);
        if (i == n || mod(a[i]) != mod(a[i+1])) {
            calc();
            v.clear();
        }
    }
    calc();
    return printf("%lld\n", res)&0;
}
