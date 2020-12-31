/*
 * @Author: Kaizyn
 * @Date: 2020-12-15 23:15:42
 * @LastEditTime: 2020-12-15 23:25:24
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e5+7;

struct Node {
  int l, r;
  bool operator <(const Node &b) const {
    return pii{l, r} < pii{b.l, b.r};
  }
};

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n;
int cnt[N];
Node a[N];
BinaryIndexedTree<int> lnode, rnode;

void discrete() {
  vector<int> d;
  for (int i = 1; i <= n; ++i) {
    d.emplace_back(a[i].l);
    d.emplace_back(a[i].r);
  }
  sort(d.begin(), d.end());
  for (int i = 1; i <= n; ++i) {
    a[i].l = lower_bound(d.begin(), d.end(), a[i].l)-d.begin()+1;
    a[i].r = lower_bound(d.begin(), d.end(), a[i].r)-d.begin()+1;
  }
}

inline void solve() {
  cin >> n;
  lnode.init(2*n);
  rnode.init(2*n);
  for (int i = 1; i <= n; ++i) cin >> a[i].l >> a[i].r;
  discrete();
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) lnode.add(a[i].l, 1);
  for (int i = 1, j; i <= n; i = j) {
    j = i+1;
    while (j <= n && a[j].l == a[i].l) ++j;
    for (int k = i; k < j; ++k) {
      cnt[k] = rnode.query(a[k].l, a[k].r)+lnode.query(a[k].l, a[k].r);
    }
    for (int k = i; k < j; ++k) {
      rnode.add(a[k].r, 1);
    }
  }
  int res = n;
  for (int i = 1; i <= n; ++i) res = min(res, n-cnt[i]);
  cout << res << endl;
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}