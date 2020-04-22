/*
 * @Author: Kaizyn
 * @Date: 2020-03-09 22:40:32
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 22:50:57
 * @FilePath: \Code\HDU\cf1312C.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 35;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k;
int bit[70], vis[70];
long long a[N];

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    memset(vis, 0, sizeof vis);
    int flag = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; a[i]; ++j) {
            bit[j] = a[i]%k;
            a[i] /= k;
            if (!bit[j]) continue;
            if (vis[j] || bit[j] > 1) flag = 0;
            vis[j] = 1;
            #ifdef DEBUG
            cout << bit[j] << " \n"[a[i] == 0];
            #endif
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
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