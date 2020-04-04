/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 19:57:03
 * @LastEditTime: 2020-04-04 20:15:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

long long n;
map<int, int> res;

inline void solve()
{
    cin >> n;
    if (n == 2) return void(cout << 1 << endl);
    res.clear();
    res[n] = 1;
    res[n-1] = 1;
    for (long long k = 2, x, d; k*k <= n; ++k) {
        if (n%k) continue;
        x = n; d = k;
        while (x%d == 0) x /= d;
        if ((x-1)%d == 0) res[d] = 1;
        if (n/k == k) continue;
        x = n; d = n/k;
        while (x%d == 0) x /= d;
        if ((x-1)%d == 0) res[d] = 1;
    }
    --n;
    for (long long k = 2; k*k <= n; ++k) {
        if (n%k) continue;
        res[k] = 1;
        res[n/k] = 1;
    }
    cout << res.size() << endl;
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