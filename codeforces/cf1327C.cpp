/*
 * @Author: Kaizyn
 * @Date: 2020-03-23 22:25:39
 * @LastEditTime: 2020-03-23 23:02:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, k;
int sx[N], sy[N], fx[N], fy[N];

inline void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> sx[i] >> sy[i];
    }
    for (int i = 1; i <= k; ++i) {
        cin >> fx[i] >> fy[i];
    }
    cout << n+m+n*m-3 << endl;
    for (int i = 1; i < n; ++i) cout << 'U';
    for (int i = 1; i < m; ++i) cout << 'L';
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < m; ++j) {
            cout << (i&1 ? 'R' : 'L');
        }
        if (i < n) cout << 'D';
    }
    cout << endl;
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