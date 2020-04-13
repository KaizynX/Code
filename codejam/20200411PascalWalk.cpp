/*
 * @Author: Kaizyn
 * @Date: 2020-04-11 10:19:54
 * @LastEditTime: 2020-04-11 10:48:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
long long c[40][40];

inline void init()
{
    // 1000 is 13
    const int sz = 34;
    for (int i = 0; i < sz; ++i) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j <= i/2; ++j) {
            c[i][j] = c[i][i-j] = c[i-1][j-1]+c[i-1][j];
        }
    }
}

inline void solve()
{
    cin >> n;
    int now = 1, line = 2;
    cout << "1 1" << endl;
    for ( ; now+line-1 <= n; now += line-1, ++line) {
        cout << line << " " << 2 << endl;
    }
    --line;
    while (now < n) {
        cout << line++ << " " << 1 << endl;
        ++now;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    init();
    #ifdef DEBUG
    for (int i = 0; i < 13; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << c[i][j] << " \n"[j==i];
        }
    }
    #endif
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ":\n";
        solve();
    }
    return 0;
}