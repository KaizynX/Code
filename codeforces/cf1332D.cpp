/*
 * @Author: Kaizyn
 * @Date: 2020-03-31 22:44:10
 * @LastEditTime: 2020-03-31 22:46:59
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

int k;
int a[10][10];

inline void solve()
{
    cin >> k;
    int bit = 0;
    while ((1<<bit) <= k) ++bit;
    for (int i = 1; i <= 3; ++i)
        for (int j = 1; j <= 3; ++j)
            a[i][j] = (1<<(bit+1))-1;
    a[1][2] = a[2][2] = 0;
    a[3][1] = a[3][3] = k;
    a[2][2] = 1<<bit;
    cout << 3 << " " << 3 << endl;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            cout << a[i][j] << " \n"[j==3];
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