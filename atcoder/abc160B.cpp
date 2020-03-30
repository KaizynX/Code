/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 21:07:03
 * @LastEditTime: 2020-03-28 21:10:45
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;

inline void solve()
{
    cin >> n;
    long long res = 0;
    res += n/500*1000;
    n %= 500;
    res += n/5*5;
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