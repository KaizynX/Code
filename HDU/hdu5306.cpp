/*
 * @Author: Kaizyn
 * @Date: 2021-02-22 15:12:17
 * @LastEditTime: 2021-02-22 16:04:58
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e6+7;

template <typename T> inline void read(T &x) {
  int c; T tag = 1;
  while(!isdigit((c=getchar()))) if(c == '-') tag = -1;
  x = c-'0';
  while(isdigit((c=getchar()))) x = (x<<1)+(x<<3) + c-'0';
  x *= tag;
}

template <typename T> void write(T x) {
  if(x < 0) x = -x, putchar('-');
  if(x > 9) write(x/10);
  putchar(x%10+'0');
}

int n, m;
int a[N];

struct Tree {
  struct TreeNode {
    int l, r, mx, se, cnt, tag;
    ll sum;
  } tr[N<<2];
  void push_up(int i) {
    tr[i].sum = tr[i<<1].sum+tr[i<<1|1].sum;
    if (tr[i<<1].mx > tr[i<<1|1].mx) {
      tr[i].mx = tr[i<<1].mx;
      tr[i].cnt = tr[i<<1].cnt;
      tr[i].se = max(tr[i<<1].se, tr[i<<1|1].mx);
    } else if (tr[i<<1].mx < tr[i<<1|1].mx) {
      tr[i].mx = tr[i<<1|1].mx;
      tr[i].cnt = tr[i<<1|1].cnt;
      tr[i].se = max(tr[i<<1|1].se, tr[i<<1].mx);
    } else {
      tr[i].mx = tr[i<<1].mx;
      tr[i].cnt = tr[i<<1].cnt+tr[i<<1|1].cnt;
      tr[i].se = max(tr[i<<1].se, tr[i<<1|1].se);
    }
  }
  void push_tag(int i, int v) {
    if (v >= tr[i].mx) return;
    tr[i].sum -= 1ll*(tr[i].mx-v)*tr[i].cnt;
    tr[i].mx = tr[i].tag = v;
  }
  void push_down(int i) {
    if (tr[i].tag == -1) return;
    push_tag(i<<1, tr[i].tag);
    push_tag(i<<1|1, tr[i].tag);
    tr[i].tag = -1;
  }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r; tr[i].tag = -1;
    if (l == r) {
      tr[i].sum = tr[i].mx = a[l];
      tr[i].cnt = 1;
      tr[i].se = -1;
      return;
    }
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
    push_up(i);
  }
  void update_min(int l, int r, int v, int i = 1) {
    if (v >= tr[i].mx) return;
    if (l <= tr[i].l && r >= tr[i].r && v > tr[i].se) return push_tag(i, v);
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) update_min(l, r, v, i<<1);
    if (r >  mid) update_min(l, r, v, i<<1|1);
    push_up(i);
  }
  int query_max(int l, int r, int i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) return tr[i].mx;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return query_max(l, r, i<<1);
    if (l >  mid) return query_max(l, r, i<<1|1);
    return max(query_max(l, r, i<<1), query_max(l, r, i<<1|1));
  }
  ll query_sum(int l, int r, int i = 1) {
    if (l <= tr[i].l && r >= tr[i].r) return tr[i].sum;
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (r <= mid) return query_sum(l, r, i<<1);
    if (l >  mid) return query_sum(l, r, i<<1|1);
    return query_sum(l, r, i<<1)+query_sum(l, r, i<<1|1);
  }
} tree;

inline void solve() {
  // cin >> n >> m;
  read(n); read(m);
  // for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) read(a[i]);
  tree.build(1, n);
  for (int i = 1, op, x, y, t; i <= m; ++i) {
    // cin >> op >> x >> y;
    read(op); read(x); read(y);
    if (op == 0) {
      // cin >> t;
      read(t);
      tree.update_min(x, y, t);
    } else if (op == 1) {
      // cout << tree.query_max(x, y) << '\n';
      write(tree.query_max(x, y)); putchar('\n');
    } else {
      // cout << tree.query_sum(x, y) << '\n';
      write(tree.query_sum(x, y)); putchar('\n');
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  read(T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}