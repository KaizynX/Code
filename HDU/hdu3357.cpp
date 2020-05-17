/*
 * @Author: Kaizyn
 * @Date: 2020-05-08 23:09:13
 * @LastEditTime: 2020-05-08 23:30:16
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 250;

int n, m;
int f[N][N];
vector<int> l, r;

inline int solve() {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            f[i][j] = 0;
        }
    }
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        if (u == v || f[v][u]) { ++res; continue; }
        f[u][v] = 1;
        for (int k = 1; k <= n; ++k) {
            if (f[k][u]) f[k][v] = 1, l.emplace_back(k);
            if (f[v][k]) f[u][k] = 1, r.emplace_back(k);
        }
        for (const int &pl : l) {
            for (const int &pr : r) {
                f[pl][pr] = 1;
            }
        }
        l.clear();
        r.clear();
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 0;
    while (cin >> n >> m && n|m) {
        cout << ++T << ". " << solve() << endl;
    }
    return 0;
}