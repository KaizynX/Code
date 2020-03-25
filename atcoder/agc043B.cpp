/*
 * @Author: Kaizyn
 * @Date: 2020-03-21 19:58:04
 * @LastEditTime: 2020-03-22 13:28:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
string a;

inline int C(const int &n, const int &k)
{
    return (n&k) == k;
}

inline void solve()
{
    cin >> n >> a;
    for (int i = 0; i < n; ++i) a[i] -= '1';
    int flag = 0, res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            flag = 1;
            res ^= C(n-1, i);
        }
    }
    if (!flag) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == 2 && C(n-1, i)) res = 2-res;
        }
    }
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