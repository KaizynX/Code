/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 21:12:21
 * @LastEditTime: 2020-03-28 21:16:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k;
int a[N];

inline void solve()
{
    cin >> k >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int res = a[1]-a[n]+k;
    for (int i = 1; i < n; ++i) res = max(res, a[i+1]-a[i]);
    cout << k-res << endl;
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