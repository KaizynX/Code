/*
 * @Author: Kaizyn
 * @Date: 2020-04-10 22:25:01
 * @LastEditTime: 2020-04-10 22:44:14
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

int n;
int p[N], c[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i] >> c[i];
    }
    int flag = 1;
    for (int i = n; i; --i) {
        c[i] -= c[i-1];
        p[i] -= p[i-1];
    }
    for (int i = 1; i <= n; ++i) {
        if (c[i] < 0 || p[i] < 0 || p[i] < c[i]) flag = 0;
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