/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 14:14:48
 * @LastEditTime: 2020-04-19 14:57:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, v;
int a[N], b[N];

inline void solve()
{
    cin >> n >> v;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    long long res = 0;
    int  now = 0;
    for (int i = 1; i <= n; ++i) {
        now += b[i];
        res += 2ll*a[i]*(now/v);
        now %= v;
    }
    if (now) res += 2*a[n];
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