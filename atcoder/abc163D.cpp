/*
 * @Author: Kaizyn
 * @Date: 2020-04-26 17:02:29
 * @LastEditTime: 2020-04-26 17:06:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, k;

inline void solve()
{
    cin >> n >> k;
    long long res = 0;
    for (int i = k; i <= n+1; ++i) {
        long long l = (0+i-1ll)*i/2,
                  r = (n+n-i+1ll)*i/2;
        res = (res+(r-l+1))%MOD;
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