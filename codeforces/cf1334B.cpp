/*
 * @Author: Kaizyn
 * @Date: 2020-04-10 22:25:21
 * @LastEditTime: 2020-04-10 22:47:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n, x;
int a[N];

inline void solve()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    int res = 0;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += a[i];
        if (sum >= 1ll*x*i) res = i;
        else break;
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