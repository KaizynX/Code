/*
 * @Author: Kaizyn
 * @Date: 2020-05-01 22:31:49
 * @LastEditTime: 2020-05-01 22:37:09
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 30;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;

inline void solve()
{
    cin >> n;
    int res = 1<<n;
    for (int i = 1; i < n/2; ++i) {
        res += 1<<i;
    }
    for (int i = n/2; i < n; ++i) {
        res -= 1<<i;
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