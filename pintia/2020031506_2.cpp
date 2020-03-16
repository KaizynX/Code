/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 15:04:42
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 15:19:13
 * @FilePath: \Code\pintia\2020031506_2.cpp
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
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] = a[i]&1;
        res += a[i];
    }
    for (int i = 0, cur = 0; i < 1<<n; ++i) {
        for (int j = 0; j < k; ++j) cur ^= a[j]^((i>>j)&1);
        if (!cur) continue;
        for (int j = k; j < n; ++j) {
            cur ^= a[j]^((i>>j)&1)^a[j-k]^((i>>(j-k))&1);
            if (!cur) break;
        }
        if (!cur) continue;
        cout << bitset<8>(i) << endl;
        res = min(res, __builtin_popcount(i));
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