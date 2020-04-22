/*
 * @Author: Kaizyn
 * @Date: 2020-04-19 14:03:30
 * @LastEditTime: 2020-04-19 14:07:32
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i)  {
        cin >> a[i];
    }
    double res = min(1.0/a[0], 1.0/a[n-1]);
    for (int i = 1; i < n; ++i) {
        res += min(1.0/a[i], 1.0/a[i-1]);
    }
    printf("%.2f\n", res);
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