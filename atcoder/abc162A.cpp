/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 20:23:56
 * @LastEditTime: 2020-04-12 20:32:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 100;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;

inline void solve()
{
    cin >> n;
    if (n%10 == 7 || n/10%10 == 7 || n/100 == 7) cout << "Yes";
    else cout << "No";
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