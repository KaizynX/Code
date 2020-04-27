/*
 * @Author: Kaizyn
 * @Date: 2020-04-22 00:13:46
 * @LastEditTime: 2020-04-23 20:02:52
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k;
int a[N];
int mina[N], maxa[N], suma[N];

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n/2; ++i) {
        mina[i] = min(a[i], a[n-i+1]);
        maxa[i] = k+max(a[i], a[n-i+1]);
        suma[i] = a[i]+a[n-i+1];
    }
    sort(mina+1, mina+n/2+1);
    sort(maxa+1, maxa+n/2+1);
    sort(suma+1, suma+n/2+1);
    int res = INF;
    for (int x = 2, now; x <= k*2; ++x) {
        now = n/2;
        // mina < x is ok
        now += n/2-(lower_bound(mina+1, mina+n/2+1, x)-mina-1);
        // maxa >= x is ok
        now += lower_bound(maxa+1, maxa+n/2+1, x)-maxa-1;
        now -= upper_bound(suma+1, suma+n/2+1, x)-lower_bound(suma, suma+n/2+1, x);
        res = min(res, now);
        #ifdef DEBUG
        cout << x << " " << now << endl;
        #endif
    }
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}