/*
 * @Author: Kaizyn
 * @Date: 2020-03-23 22:25:09
 * @LastEditTime: 2020-03-23 22:37:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k;

inline void solve()
{
    cin >> n >> k;
    long long mv = (1+2*k-1)*k/2;
    if (mv > n || (n&1)!=(k&1)) { cout << "NO" << endl; }
    else cout << "YES" << endl;
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