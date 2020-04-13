/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 20:26:40
 * @LastEditTime: 2020-04-12 20:27:21
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

int n;

inline void solve()
{
    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        if (i%3 && i%5) res += i;
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