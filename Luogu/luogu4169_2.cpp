/*
 * @Author: Kaizyn
 * @Date: 2021-02-18 19:44:05
 * @LastEditTime: 2021-02-18 20:11:39
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
const int N = 6e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, -INF); }
  void clear(const int &x) { for (int i = x; i <= n; i += i&-i) tr[i] = -INF; }
  void update(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] = max(tr[i], v); }
  T query(const int &x) { T res = -INF; for (int i = x ; i; i -= i&-i) res = max(res, tr[i]); return res; }
};

struct Node {
  int id, t, x, y;
  bool operator <(const Node &b) const {
    return id < b.id;
  }
};

int n, m;
int res[N], dx[N], dy[N];
Node a[N], b[N], c[N];
BinaryIndexedTree<int> tree;

void discrete() {
  for (int i = 1; i <= n+m; ++i) dx[i] = c[i].x;
  for (int i = 1; i <= n+m; ++i) dy[i] = c[i].y;
  sort(dx+1, dx+n+m+1);
  sort(dy+1, dy+n+m+1);
  int kx = unique(dx+1, dx+n+m+1)-dx;
  int ky = unique(dy+1, dy+n+m+1)-dy;
  for (int i = 1; i <= n+m; ++i) {
    c[i].x = lower_bound(dx+1, dx+kx)-dx;
    c[i].y = lower_bound(dy+1, dy+ky)-dy;
  }
}

void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l+r)>>1, i = l, j = mid+1;
  cdq(l, mid); cdq(mid+1, r);
  for (int k = l; k <= r; ++k) {
    if (j > r || (i <= mid && a[i].x <= a[j].x)) {
      if (a[i].t == 1) tree.update(a[i].y, dx[a[i].x]+dy[a[i].y]);
      b[k] = a[i++];
    } else {
      if (a[j].t == 2) res[a[j].id] = min(res[a[j].id], a[j].x+a[j].x-tree.query(a[j].y));
      b[k] = a[j++];
    }
  }
  for (int k = l; k <= mid; ++k) tree.clear(a[k].y);
  for (int k = l; k <= r; ++k) a[k] = b[k];
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    c[i].id = i;
    c[i].t = 1;
    cin >> c[i].x >> c[i].y;
  }
  for (int i = n+1; i <= n+m; ++i) {
    c[i].id = i;
    cin >> c[i].t >> c[i].x >> c[i].y;
  }
  tree.build(n+m);
  for (int i = 0; i < 4; ++i) {
    for (int j = 1; j <= n+m; ++j) a[i] = c[i];
    if (i&1) a[i].x = -a[i].x;
    if (i&2) a[i].y = -a[i].y;
    cdq(1, n+m);
  }
  tree.init(1e6);
  cdq(1, n+m);
  sort(a+1, a+n+m+1);
  for (int i = 1; i <= n+m; ++i) a[i].x = -a[i].x;
  cdq(1, n+m);
  sort(a+1, a+n+m+1);
  for (int i = 1; i <= n+m; ++i) a[i].y = -a[i].y;
  cdq(1, n+m);
  sort(a+1, a+n+m+1);
  for (int i = 1; i <= n+m; ++i) a[i].x = -a[i].x;
  cdq(1, n+m);
  for (int i = 1; i <= n+m; ++i) {
    if (c[i].t == 2) {
      cout << res[c[i].id] << '\n';
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}