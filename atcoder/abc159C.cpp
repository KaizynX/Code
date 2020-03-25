/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 19:58:40
 * @LastEditTime: 2020-03-22 20:06:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

inline void solve()
{
    int l;
    cin >> l;
    printf("%.7f\n", pow(l/3.0, 3));
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