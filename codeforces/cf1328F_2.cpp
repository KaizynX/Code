/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 22:33:29
 * @LastEditTime: 2020-03-27 00:00:53
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const long long INF = 1e18;
typedef pair<int, int> pii;

int n, k;
int a[N];
long long s[N];

long long calc(const int &mid)
{
    int r = upper_bound(a+1, a+n+1, mid)-a,
        l = lower_bound(a+1, a+n+1, mid)-a;
    int p = l;
    long long res = (s[n]-s[p-1]-mid*(n-p+1ll))+((p-1ll)*mid-s[p-1]);
    res -= min(n-k, n-(r-l));
    // return min({res, fff(1, k, mid), fff(n-k+1, n, mid)});
    return res;
}

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i-1]+a[i];
    }
    long long res = INF;
    // [1, k]
    res = min(res, 1ll*k*a[k]-s[k]);
    // [n-k+1, n]
    res = min(res, s[n]-s[n-k]-1ll*a[n-k+1]*k);
    for (int i = 1; i <= n; ++i)
        res = min(res, calc(a[i]));
    int l = a[1], r = a[n];
    while (l < r) {
        int lmid = (l+r)>>1, rmid = (lmid+r)>>1;
        long long lv = calc(lmid), rv = calc(rmid);
        res = min({res, lv, rv});
        if (lv > rv) r = rmid;
        else l = lmid+1;
    }
    for (int i = max(a[1], l-100000); i <= min(a[n], l+100000); ++i) {
        res = min(res, calc(i));
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}