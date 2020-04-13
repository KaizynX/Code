/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 20:18:14
 * @LastEditTime: 2020-04-12 20:22:46
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
char s[N];

inline void solve()
{
    cin >> n >> (s+1);
    int r = 0, g = 0, b = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == 'R') ++r;
        if (s[i] == 'G') ++g;
        if (s[i] == 'B') ++b;
    }
    long long res = 1ll*r*g*b;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; i+j+j <= n; ++j) {
            if (s[i] != s[i+j] && s[i] != s[i+j+j] && s[i+j] != s[i+j+j]) --res;
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