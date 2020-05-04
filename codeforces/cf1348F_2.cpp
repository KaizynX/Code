/*
 * @Author: Kaizyn
 * @Date: 2020-05-02 13:23:59
 * @LastEditTime: 2020-05-02 14:41:08
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

struct Node {
    int l, r, id;
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.r > rhs.r;
    }
};

int n;
int rk[N], res[N];
Node a[N], b[N];
priority_queue<Node> q;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
        b[i] = a[i];
    }
    sort(a+1, a+n+1, [&](const Node &lhs, const Node &rhs) {
      return lhs.l == rhs.l ? lhs.r < rhs.r : lhs.l < rhs.l;
    });
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= n && a[j].l == i) q.push(a[j++]);
        rk[i] = q.top().id;
        q.pop();
    }
    int flag = 0;
    if (n > 1 && b[rk[1]].r >= n && b[rk[n]].l <= 1) flag = n;
    for (int i = 1; i < n; ++i) {
        if (b[rk[i]].r >= i+1 && b[rk[i+1]].l <= i) {
            flag = i;
            break;
        }
    }
    cout << (flag ? "NO" : "YES") << endl;
    for (int i = 1; i <= n; ++i) res[rk[i]] = i;
    for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
    if (!flag) return;
    if (flag == n) swap(rk[1], rk[n]);
    else swap(rk[flag], rk[flag+1]);
    for (int i = 1; i <= n; ++i) res[rk[i]] = i;
    for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
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