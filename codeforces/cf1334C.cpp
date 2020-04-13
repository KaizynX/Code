/*
 * @Author: Kaizyn
 * @Date: 2020-04-10 22:25:28
 * @LastEditTime: 2020-04-10 22:58:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int n;
long long a[N], b[N], c[N];

inline void solve()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
        c[i] = max(0ll, a[i]-b[(i-1+n)%n]);
    }
    long long res = 0, tag = a[0]-c[0];
    for (int i = 0; i < n; ++i) {
        res += max(0ll, c[i]);
        tag = min(tag, a[i]-c[i]);
    }
    cout << res+tag << endl;
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