/*
 * @Author: Kaizyn
 * @Date: 2020-04-11 21:06:53
 * @LastEditTime: 2020-04-11 21:10:35
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e5+7;
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
    for (int i = 1; i <= n; ++i) {
        for (int j = i*2; j <= n; j += i) a[j] = i;
    }
    sort(a+2, a+n+1);
    for (int i = 2; i <= n; ++i) cout << a[i] << " \n"[i==n];
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