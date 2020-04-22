/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 14:42:46
 * @LastEditTime: 2020-04-19 14:51:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int w[N], u[N], v[N];
long long sumw[N], sumv[N];

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> w[i] >> u[i];
        if (u[i]) cin >> v[i];
        else v[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        sumw[i] = sumw[i-1]+w[i];
        sumv[i] = sumv[i-1]+v[i];
    }
    long long noww = 0, nowv = 0, res = 0;
    for (int i = n, l = n; i >= 0; --i) {
        if (noww > m) break;

        l = min(l, i);
        while (l && sumw[l]+noww > m) --l;
        res = max(res, nowv+sumv[l]);

        noww += w[i];
        nowv += v[i];
    }
    cout << res << endl;
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