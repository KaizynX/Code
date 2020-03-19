/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 22:32:45
 * @LastEditTime: 2020-03-19 22:45:54
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

inline void solve()
{
    int n;
    cin >> n;
    if (n == 1) { cout << -1 << endl; return; }
    if ((n*2+1)%3) {
        for (int i = 1; i < n; ++i) cout << 2;
        cout << 3 << endl;
    } else {
        for (int i = 1; i < n-1; ++i) cout << 2;
        cout << 33 << endl;
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