/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 21:30:37
 * @LastEditTime: 2020-03-31 21:45:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int a, b, c, d, x, y, xl, xr, yl, yr;

inline void solve()
{
    cin >> a >> b >> c >> d;
    cin >> x >> y >> xl >> yl >> xr >> yr;
    x += -a+b;
    y += -c+d;
    if (((a || b) && x == xl && x == xr) ||
        ((c || d) && y == yl && y == yr)) return void(cout << "No" << endl);
    if (x < xl || x > xr || y < yl || y > yr) return void(cout << "No" << endl);
    cout << "Yes" << endl;
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