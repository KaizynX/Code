/*
 * @Author: Kaizyn
 * @Date: 2020-05-02 22:12:51
 * @LastEditTime: 2020-05-03 10:17:36
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

int n, m;

inline void solve()
{
    cin >> n >> m;
    /*
    for (int i = 1; i <= m; ++i) {
        if (n&1) cout << i << " " << n-i << endl;
        else cout << i << " " << n-i+1 << endl;
    }
    */
    if (n&1) {
        for (int i = 1; i <= m; ++i) cout << i << " " << n-i << endl;
    } else {
        for (int i = m, j = 1; i > 0; ++j, i -= 2) {
            cout << j << " " << j+i << endl;
        }
        for (int i = m-1, j = n; i > 0; --j, i -= 2) {
            cout << j << " " << j-i << endl;
        }
    }
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