/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 22:36:37
 * @LastEditTime: 2020-04-12 22:45:07
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

int n;
int vis[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        for (int j = i+1; ; ++j) {
            if (vis[j]) continue;
            if (vis[i^j]) continue;
            cout << i << " " << j << " " << (i^j) << endl;
            vis[i] = vis[j] = vis[i^j] = 1;
            break;
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