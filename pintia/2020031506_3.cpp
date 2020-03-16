/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 19:45:53
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 19:50:11
 * @FilePath: \Code\pintia\2020031506_3.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k;
int a[N], c[N][2];

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        ++c[i%k][a[i]&1];
    }
    int res = 0, mv = INF, c0 = 0, c1 = 0;
    for (int i = 0; i < k; ++i) {
        if (c[i][0] < c[i][1]) {
            ++c1;
            res += c[i][0];
            mv = min(mv, c[i][1]-c[i][0]);
        } else  {
            ++c0;
            res += c[i][1];
            mv = min(mv, c[i][0]-c[i][1]);
        }
    }
    if (c1&1) res += mv;
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