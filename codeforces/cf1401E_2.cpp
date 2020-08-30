/*
 * @Author: Kaizyn
 * @Date: 2020-08-28 14:19:35
 * @LastEditTime: 2020-08-28 15:36:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int M = 1e6;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[M+7];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

struct Node {
  int x, l, r;
};

int n, m;
Node hor[N], ver[N];
BinaryIndexedTree<int> bit;

inline void solve() {
  long long res = 0;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> hor[i].x >> hor[i].l >> hor[i].r;
    if (hor[i].l == 0 && hor[i].r == M) ++res;
    if (hor[i].l == 0) hor[i].l = 1;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> ver[i].x >> ver[i].l >> ver[i].r;
    if (ver[i].l == 0 && ver[i].r == M) ++res;
  }
  sort(hor+1, hor+n+1, [](Node &nd1, Node &nd2) {
    return nd1.x < nd2.x;
  });
  sort(ver+1, ver+m+1, [](Node &nd1, Node &nd2) {
    return nd1.l == nd2.l ? nd1.r < nd2.r : nd1.l < nd2.l;
  });
  bit.init(M);
  for (int vi = 1, hi = 1; vi <= m && ver[vi].l == 0; ++vi) {
    while (hi <= n && hor[hi].x <= ver[vi].r) {
      bit.add(hor[hi].l, hor[hi].r, 1);
      ++hi;
    }
    res += bit.query(ver[vi].x);
  }
  bit.init(M);
  for (int vi = m, hi = n; vi >= 1 && ver[vi].l != 0; --vi) {
    while (hi >= 1 && hor[hi].x >= ver[vi].l) {
      bit.add(hor[hi].l, hor[hi].r, 1);
      --hi;
    }
    res += bit.query(ver[vi].x);
  }
  cout << res+1 << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}