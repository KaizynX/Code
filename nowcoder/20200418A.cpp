/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 11:31:02
 * @LastEditTime: 2020-04-18 12:15:23
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int a[4];

inline void solve()
{
    for (int i = 0; i < 4; ++i) cin >> a[i];
    sort(a, a+4);
    int res = INF;
    do {
        res = min(res, abs(a[0]+a[1]-a[2]-a[3]));
    } while (next_permutation(a, a+4));
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