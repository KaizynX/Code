/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 13:05:27
 * @LastEditTime: 2020-04-18 13:07:12
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

inline void solve()
{
    int n;
    cin >> n;
    if (n == 1) return void(cout << "1\n1\n");
    if (n == 2) return void(cout << "2\n0\n11\n");
    cout << n-1 << endl;
    for (int i = 2; i <= n; ++i) {
        cout << 0;
        for (int j = 2; j < i; ++j) cout << 1;
        cout << 0 << endl;
    }
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