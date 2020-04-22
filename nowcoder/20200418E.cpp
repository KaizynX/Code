/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 12:24:08
 * @LastEditTime: 2020-04-18 12:26:54
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
int a[N];

inline void solve()
{
    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        res += a[i]-i+1;
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