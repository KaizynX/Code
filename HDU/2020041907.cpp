/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 13:54:00
 * @LastEditTime: 2020-04-19 14:01:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int M = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int t[M];

int qpow(int a, long long p) {
    int res = 0;
    while (p) {
        if (p&1) res = res*a%m;
        a = a*a%m;
        p >>= 1;
    }
    return res;
}

inline void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) t[i] = 0;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        ++t[a%m];
    }
    if (t[0]) return void(cout << 0 << endl);
    for (int i = 0; i < m; ++i) {
        if (t[i] > 1) return void(cout << 0 << endl);
    }
    int res = 1;
    for (int i = 1; i < m; ++i) {
        for (int j = i+1; j < m; ++j) {
            if (t[i] && t[j]) res = res*(j-i)%m;
        }
    }
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