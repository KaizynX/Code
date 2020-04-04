/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 20:48:15
 * @LastEditTime: 2020-04-04 20:50:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

long long n, k;

inline void solve()
{
    cin >> n >> k;
    n %= k;
    cout << min(n, k-n) << endl;
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