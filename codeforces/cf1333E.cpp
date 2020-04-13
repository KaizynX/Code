/*
 * @Author: Kaizyn
 * @Date: 2020-04-09 10:59:09
 * @LastEditTime: 2020-04-09 11:11:25
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

const int gen[3][3] = {
{1,2,4},
{5,3,8},
{9,6,7}
};

int n;
int a[N][N];

inline void solve()
{
    cin >> n;
    if (n < 3) return void(cout << -1 << endl);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            a[n-3+i][j] = gen[i][j]+n*n-9;
        }
    }
    for (int t = 4, val = n*n-9; t <= n; ++t) {
        if (t&1) {
            for (int i = n-1; i > n-t; --i) a[i][t-1] = val--;
            for (int i = t-1; i >= 0; --i) a[n-t][i] = val--;
        } else {
            for (int i = 0; i < t; ++i) a[n-t][i] = val--;
            for (int i = n-t+1; i < n; ++i) a[i][t-1] = val--;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a[i][j] << " \n"[j==n-1];
        }
    }
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
