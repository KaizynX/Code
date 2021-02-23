/*
 * @Author: Kaizyn
 * @Date: 2021-02-18 19:26:31
 * @LastEditTime: 2021-02-18 20:24:37
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
  int id, t, x, y, c;
  bool operator <(const Node &b) const {
    return id < b.id;
  }
};

int n, m;
Node a[N], b[N];
BinaryIndexedTree<int> tree;

void cdq(int l, int r) {
  if (l == r) return;
  int mid = (l+r)>>1, i = l, j = mid+1;
  cdq(l, mid); cdq(mid+1, r);
  for (int k = l; k <= r; ++k) {
    if (j > r || (i <= mid && a[i].x <= a[j].x)) {
      if (a[i].t == 1) tree.update(a[i].y, a[i].x+a[i].y);
      b[k] = a[i++];
    } else {
      if (a[j].t == 2) a[j].c = min(a[j].c, a[j].x+a[j].y-tree.query(a[j].y));
      b[k] = a[j++];
    }
  }
  for (int k = l; k <= mid; ++k) if (a[k].t == 1) tree.clear(a[k].y);
  for (int k = l; k <= r; ++k) a[k] = b[k];
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    a[i].id = i;
    a[i].c = INF;
    a[i].t = 1;
    cin >> a[i].x >> a[i].y;
    ++a[i].x; ++a[i].y;
  }
  for (int i = n+1; i <= n+m; ++i) {
    a[i].id = i;
    a[i].c = INF;
    cin >> a[i].t >> a[i].x >> a[i].y;
    ++a[i].x; ++a[i].y;
  }
  tree.init(1e6+1);
  cdq(1, n+m);

  sort(a+1, a+n+m+1);
  for (int i = 1; i <= n+m; ++i) a[i].x = 1e6+2-a[i].x;
  cdq(1, n+m);

  sort(a+1, a+n+m+1);
  for (int i = 1; i <= n+m; ++i) a[i].y = 1e6+2-a[i].y;
  cdq(1, n+m);

  sort(a+1, a+n+m+1);
  for (int i = 1; i <= n+m; ++i) a[i].x = 1e6+2-a[i].x;
  cdq(1, n+m);

  sort(a+1, a+n+m+1);
  for (int i = n+1; i <= n+m; ++i) {
    if (a[i].t == 2) {
      cout << a[i].c << '\n';
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