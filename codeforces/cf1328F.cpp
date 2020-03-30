/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 22:33:29
 * @LastEditTime: 2020-03-26 23:42:57
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

long long fff(const int &l, const int &r, const int &mid)
{
    int p = lower_bound(a+l, a+r+1, mid)-a;
    // [l, p-1] [p, r]
    return s[r]-s[p-1]-mid*(r-p+1ll)+1ll*(p-l)*mid-s[p-1]+s[l-1];
}

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
    #ifdef DEBUG
    for (int i = a[1]; i <= a[n]; ++i) {
        cout << i << " " <<  calc(i) << " " << fff(1, k, i) << " " << fff(n-k+1, n, i) << endl;
    }
    #endif
    int resi = 0;
    long long res = INF;
    for (int i = 1; i <= n; ++i) {
        long long tmp = calc(a[i]);
        if (tmp < res) {
            res = tmp;
            resi = a[i];
        }
    }
    for (int i = max(a[1], resi-100000); i <= min(resi+100000, a[n]); ++i) {
        res = min(res, calc(i));
    }
    // [1, k]
    res = min(res, 1ll*k*a[k]-s[k]);
    // [n-k+1, n]
    res = min(res, s[n]-s[n-k]-1ll*a[n-k+1]*k);
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