/*
 * @Author: Kaizyn
 * @Date: 2020-05-01 22:32:07
 * @LastEditTime: 2020-05-01 23:33:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;

inline void solve()
{
    cin >> n;
    int b = 1;
    while ((1<<b)-1 < n) ++b;
    --b;
    cout << b << endl;
    int rest = n-b-1, now = 1;
    for (int i = b, cur; i >= 1; --i) {
        cur = min(rest/i, now);
        cout << cur << " ";
        now += cur;
        rest -= cur*i;
    }
    cout << endl;
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