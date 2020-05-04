/*
 * @Author: Kaizyn
 * @Date: 2020-05-02 13:23:59
 * @LastEditTime: 2020-05-02 13:57:10
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
    /*
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.l == rhs.l ? lhs.r < rhs.r : lhs.l < rhs.l;
    }
    */
    friend bool operator < (const Node &lhs, const Node &rhs) {
        return lhs.r == rhs.r ? lhs.l < rhs.l : lhs.r < rhs.r;
    }
};

int n;
int cnt[N], res[N];
Node a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].id = i;
        ++cnt[a[i].l];
        if (a[i].l == a[i].r) cnt[a[i].l] = -n;
    }
    sort(a+1, a+n+1);
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        if (cnt[a[i].l] > 1) flag = 1;
    }
    if (flag) {
        cout << "NO\n";
        for (int i = 1; i <= n; ++i) res[a[i].id] = i;
        for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
        for (int i = 1; i < n; ++i) {
            if (a[i].r >= i+1 && a[i+1].l <= i) {
                swap(a[i], a[i+1]);
                break;
            }
        }
        for (int i = 1; i <= n; ++i) res[a[i].id] = i;
        for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
    } else {
        cout << "YES\n";
        for (int i = 1; i <= n; ++i) res[a[i].id] = i;
        for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
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