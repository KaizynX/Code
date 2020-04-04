/*
 * @Author: Kaizyn
 * @Date: 2020-04-04 20:42:22
 * @LastEditTime: 2020-04-04 20:46:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, m;
int a[N];

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int sum = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) sum += a[i];
    sum = (sum+4*m-1)/(4*m);
    for (int i = 1; i <= n; ++i) {
        if (a[i] >= sum) ++cnt;
    }
    cout << (cnt >= m ? "Yes" : "No") << endl;
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