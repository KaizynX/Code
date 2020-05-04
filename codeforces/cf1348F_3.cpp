/*
 * @Author: Kaizyn
 * @Date: 2020-05-02 13:23:59
 * @LastEditTime: 2020-05-03 13:16:11
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
int rk[N], rkr[N], res[N];
Node a[N], b[N];
priority_queue<Node> q;

struct SegmentTree {
    struct TreeNode {
        int v, l, r;
    } tr[N<<2];
    int mv(const int &x, const int &y) {
        return b[rk[x]].l < b[rk[y]].l ? x : y;
    }
    void build(const int &l, const int &r, const int &i = 1) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) return void(tr[i].v = l);
        int mid = (l+r)>>1;
        build(l, mid, i<<1);
        build(mid+1, r, i<<1|1);
        tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v);
    }
    int query(const int &l, const int &r, const int &i = 1) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
        int mid = (tr[i].l+tr[i].r)>>1, res = 0;
        if (l <= mid) res = mv(res, query(l, r, i<<1));
        if (r >  mid) res = mv(res, query(l, r, i<<1|1));
        return res;
    }
} ST;

inline void print() {
    for (int i = 1; i <= n; ++i) res[rk[i]] = i;
    for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
}

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

    b[0].l = INF;
    ST.build(1, n);
    for (int i = 1; i <= n; ++i) {
        if (i+1 > b[rk[i]].r) continue;
        int j = ST.query(i+1, b[rk[i]].r);
        if (b[rk[j]].l <= i) {
            cout << "NO" << endl;
            print();
            swap(rk[i], rk[j]);
            print();
            return;
        }
    }
    cout << "YES" << endl;
    print();
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}