/*
 * @Author: Kaizyn
 * @Date: 2020-04-03 22:30:06
 * @LastEditTime: 2020-04-03 23:00:57
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

struct Node
{
    int id, l;
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.l < rhs.l;
    }
} a[N];

int n, m;
int res[N];

inline void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> a[i].l, a[i].id = i;

    long long sum = 0;
    for (int i = 1; i <= m; ++i) sum += a[i].l;
    if (sum < n) return void(cout << -1 << endl);

    // sort(a+1, a+m+1);
    res[m+1] = n+1;
    for (int i = m, l, r; i; --i) {
        // p <= n-a[i].l+1
        // p >= p-a[i].l+1
        // p >= i
        r = min(res[i+1]-1, n-a[i].l+1);
        l = max(i, res[i+1]-a[i].l);
        if (l > r) return void(cout << -1 << endl);
        res[i] = l;
    }
    for (int i = 1; i <= m; ++i) cout << res[i] << " \n"[i==m];
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