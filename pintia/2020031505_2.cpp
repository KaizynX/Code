/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 20:19:26
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 20:22:38
 * @FilePath: \Code\pintia\2020031505_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const long long INF = 1e18;
typedef pair<int, int> pii;

int n, k;
int x[N], y[N];
long long d[N][N][N], res[N];

inline void solve()
{
    cin >> n >> k;
    fill(res, res+N, INF);
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int l = 1; l <= n; ++l) {
                d[i][j][l] = 1ll*abs(x[i]-x[l])+1ll*abs(y[j]-y[l]);
            }
            sort(d[i][j]+1, d[i][j]+n+1);
            for (int l = 1; l <= k; ++l) {
                d[i][j][l] += d[i][j][l-1];
                res[l] = min(res[l], d[i][j][l]);
            }
        }
    }
    for (int i = 1; i <= k; ++i) cout << res[i] << endl;
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