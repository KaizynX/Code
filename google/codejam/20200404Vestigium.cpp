/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 09:17:09
 * @LastEditTime: 2020-04-04 09:21:31
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

int n, k, r, c;
int a[N][N];
map<int, int> vis;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    k = r = c = 0;
    for (int i = 1; i <= n; ++i) k += a[i][i];
    for (int i = 1; i <= n; ++i) {
        vis.clear();
        for (int j = 1; j <= n; ++j) vis[a[i][j]] = 1;
        r += vis.size() < n;
    }
    for (int j = 1; j <= n; ++j) {
        vis.clear();
        for (int i = 1; i <= n; ++i) vis[a[i][j]] = 1;
        c += vis.size() < n;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
        cout << "Case #" << i << ": " << k << " " << r << " " << c << endl;
    }
    return 0;
}