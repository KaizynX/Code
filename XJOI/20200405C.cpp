/*
 * @Author: Kaizyn
 * @Date: 2020-04-05 14:31:28
 * @LastEditTime: 2020-04-05 16:34:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 998244353;
const long long INF = 1e18;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T>
T exgcd(const T a, const T b, T &x, T &y)
{
    if (!b) { x = 1; y = 0; return a; }
    T d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo = MOD)
{
    T x, y;
    exgcd(a, mo, x, y);
    return (x%mo+mo)%mo;
}

int n, m;
int a[N];
int v[N], w[N];
long long dp[N];

template <typename T>
inline void update(T &x, const T &y) { if (x == -1 || y < x) x = y; }

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> v[i] >> w[i];

    memset(dp, -1, sizeof(long long)*(a[n]+3));
    for (int i = 1; i <= a[1]; ++i) dp[i] = 0;
    /*
    for (int i = 1; i < n; ++i) { // on state i+1
        for (int j = a[i]+1; j <= a[i+1]; ++j) {
            for (int k = 1; k <= m; ++k) if (w[k] <= a[i]) {
                update(dp[j], dp[j-w[k]]+v[k]);
            }
            if (dp[j] == -1) return void(cout << -1 << endl);
        }
    }
    */
    for (int i = 1; i < n; ++i) { // on state i+1
        for (int j = a[i]+1; j <= a[i+1]; ++j) {
            int cnt = 0;
            long long sum = 0;
            for (int k = 1; k <= m; ++k) if (w[k] <= a[i]) {
                sum += dp[j-w[k]]+v[k];
                ++cnt;
            }
            if (!cnt) return void(cout << -1 << endl);
            dp[j] = sum/cnt;
        }
    }
    long long res = 0;
    for (int i = 1; i <= a[n]; ++i) {
        res += dp[i];
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