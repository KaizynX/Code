/*
 * @Author: Kaizyn
 * @Date: 2021-07-11 17:50:40
 * @LastEditTime: 2021-07-11 22:04:37
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e5+7;

struct Tree {
#define rt tr[i]
#define lc tr[i<<1]
#define rc tr[i<<1|1]
  struct TreeNode {
    int l, r;
    int g[2]; // r+1不选/选时l选不选
    int c[2]; // r+1不选/选时中间选了几个
    ll s[2];  // r+1不选/选时中间选的和
  } tr[N<<2];
  void build(int l, int r, int i = 1) {
    rt.g[0] = rt.g[1] = 0;
    rt.c[0] = rt.c[1] = 0;
    rt.s[0] = rt.s[1] = 0;
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void push_up(int i) {
    rt.g[0] = lc.g[rc.g[0]];
    rt.g[1] = lc.g[rc.g[1]];
    rt.c[0] = rc.c[0]+lc.c[rc.g[0]];
    rt.c[1] = rc.c[1]+lc.c[rc.g[1]];
    rt.s[0] = rc.s[0]+lc.c[rc.g[0]];
    rt.s[1] = rc.s[1]+lc.c[rc.g[1]];
  }
  void update(int x, int v, int i = 1) {
    if (rt.l == rt.r) {
      rt.g[0] = 1;
      rt.c[0] = 1;
      rt.s[0] = v;
      return;
    }
    int mid = (rt.l+rt.r)>>1;
    if (x <= mid) update(x, v, i<<1);
    else update(x, v, i<<1|1);
    push_up(i);
  }
  ll query(int k, int rg = 0, int i = 1) {
    if (rt.l == rt.r) return rt.s[rg];
    if (rc.c[rg] > k) return query(k, rg, i<<1|1);
    return rc.s[rg]+query(k-rc.c[rg], rc.g[rg], i<<1);
  }
};

struct Query {
  int a, k, id;
  bool operator <(const Query &b) const {
    return a < b.a;
  }
};

int n, m;
int skill[N];
ll res[N];
pii a[N];
Tree tree;
Query q[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
    skill[i] = a[i].second;
  }
  sort(a+1, a+n+1);
  sort(skill+1, skill+n+1);
  tree.build(1, n);
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> q[i].a >> q[i].k;
    q[i].id = i;
  }
  sort(q+1, q+m+1);
  for (int i = 1, j = 1; i <= m; ++i) {
    while (j <= n && a[i].first <= q[i].a) {
      tree.update(
          lower_bound(skill+1, skill+n+1, a[j].second)-skill,
          a[j].second
      );
      ++j;
    }
    res[q[i].id] = tree.query(q[i].k);
  }
  for (int i = 1; i <= m; ++i) {
    cout << res[i] << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}