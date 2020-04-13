/*
 * @Author: Kaizyn
 * @Date: 2020-04-08 22:31:30
 * @LastEditTime: 2020-04-08 22:39:39
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << (i == 1 && j == 1 ? 'W' : 'B');
        }
        cout << endl;
    }
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