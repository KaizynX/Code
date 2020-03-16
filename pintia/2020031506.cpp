/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 14:50:01
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 15:24:22
 * @FilePath: \Code\pintia\2020031506.cpp
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
int a[N], b[N];

inline void solve()
{
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] = a[i]&1;
        res += a[i];
    }
    for (int i = 0, cur, cnt; i < (1ll<<(k-1)); ++i) {
        cnt = __builtin_popcount(i);
        for (int j = 1; j <= n; ++j) b[j] = a[j];
        for (int j = 0; j < k-1; ++j) if ((i>>j)&1) b[j+1] ^= 1;
        cur = 0;
        for (int j = 1; j < k; ++j) cur ^= b[j];
        for (int j = k; j <= n; ++j) {
            cur ^= b[j]^b[j-k];
            if (cur) {
                cur ^= 1;
                b[j] ^= 1;
                ++cnt;
            }
        }
        res = min(res, cnt);
    }
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