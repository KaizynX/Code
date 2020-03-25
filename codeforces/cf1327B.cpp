/*
 * @Author: Kaizyn
 * @Date: 2020-03-23 22:25:45
 * @LastEditTime: 2020-03-23 22:48:47
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int mar[N], vis[N];
vector<int> g[N];

inline void solve()
{
    cin >> n;
    memset(mar, 0, sizeof(int)*(n+3));
    memset(vis, 0, sizeof(int)*(n+3));
    for (int i = 1, k; i <= n; ++i) {
        cin >> k;
        g[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : g[i]) {
            if (!vis[j]) {
                vis[j] = i;
                mar[i] = j;
                break;
            }
        }
    }
    int u = 0, v = 0;
    for (int i = 1; i <= n; ++i) {
        if (!mar[i]) u = i;
        if (!vis[i]) v = i;
    }
    if (u && v) {
        cout << "IMPROVE" << endl << u << " " << v << endl;
    } else {
        cout << "OPTIMAL" << endl;
    }
    for (int i = 1; i <= n; ++i) vector<int>().swap(g[i]);
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