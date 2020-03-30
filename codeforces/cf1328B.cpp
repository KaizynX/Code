/*
 * @Author: Kaizyn
 * @Date: 2020-03-27 00:27:03
 * @LastEditTime: 2020-03-27 00:34:07
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
long long k;

inline void solve()
{
    cin >> n >> k;
    int a, b;
    long long now = 0;
    a = 2; b = 1;
    while (now+a-1 < k) {
        now += a-1;
        ++a;
    }
    b = k-now;
    string res(n, 'a');
    res[n-a] = 'b';
    res[n-b] = 'b';
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