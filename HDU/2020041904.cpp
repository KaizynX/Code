/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 14:52:20
 * @LastEditTime: 2020-04-19 16:08:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int a[N];
long long b[N], c[N];

inline long long get_max() {
    long long res = b[1];
    for (int i = 2; i < n; ++i) {
        res = max(res, b[i]);
    }
    return res;
}

inline long long get_min() {
    long long res = c[1];
    for (int i = 2; i < n; ++i) {
        res = min(res, c[i]);
    }
    return res;
}

inline void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", a+i);
    long long res = 0, base = 0;
    for (int i = 1; i < n; ++i) base += abs(a[i+1]-a[i]);
    res = base;
    for (int i = 2; i < n; ++i) {
        res = max(res, base-abs(a[i]-a[i+1])+abs(a[1]-a[i+1]));
        res = max(res, base-abs(a[i]-a[i-1])+abs(a[n]-a[i-1]));
    }

    for (int i = 1; i < n; ++i) {
        b[i] = 1ll*a[i]+a[i+1]-abs(a[i]-a[i+1]);
        c[i] = 1ll*a[i]+a[i+1]+abs(a[i]-a[i+1]);
    }
    res = max(res, base+get_max()-get_min());
    for (int i = 1; i < n; ++i) {
        b[i] = 1ll*a[i]-a[i+1]-abs(a[i]-a[i+1]);
        c[i] = 1ll*a[i]-a[i+1]+abs(a[i]-a[i+1]);
    }
    res = max(res, base+get_max()-get_min());
    for (int i = 1; i < n; ++i) {
        b[i] = -1ll*a[i]+a[i+1]-abs(a[i]-a[i+1]);
        c[i] = -1ll*a[i]+a[i+1]+abs(a[i]-a[i+1]);
    }
    res = max(res, base+get_max()-get_min());
    for (int i = 1; i < n; ++i) {
        b[i] = -1ll*a[i]-a[i+1]-abs(a[i]-a[i+1]);
        c[i] = -1ll*a[i]-a[i+1]+abs(a[i]-a[i+1]);
    }
    res = max(res, base+get_max()-get_min());
    printf("%lld\n", res);
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}