/*
 * @Author: Kaizyn
 * @Date: 2020-04-26 22:34:01
 * @LastEditTime: 2020-04-26 22:39:12
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 10;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int x, y, a, b;

inline void solve()
{
    cin >> x >> y >> a >> b;
    long long res = 0;
    if (x < 0 && y < 0) x = -x, y = -y;
    if (x < 0 || y < 0) {
        cout << 1ll*(abs(x)+abs(y))*a << endl;
    } else {
        res = 1ll*(x+y)*a;
        int z = min(x, y);
        x -= z; y -= z;
        res = min(res, 1ll*z*b+1ll*(x+y)*a);
        cout << res << endl;
    }
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