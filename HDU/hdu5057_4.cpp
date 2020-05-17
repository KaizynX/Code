/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 11:01:35
 * @LastEditTime: 2020-05-15 13:41:09
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
const int pw10[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

template <typename T>
struct BinaryIndexedTree
{
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
  void add(const int &x, const T &v) { for (int i = x ; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
  template <typename TT>
  void init(const int &_n, const TT a[]) {
    n = _n; clear();
    for (int i = 1; i <= n; ++i) {
      tr[i] += a[i];
      if (i+(i&-i) <= n) tr[i+(i&-i)] += tr[i];
    }
  }
};

struct Query {
  char op;
  int l, r, d, p;
};

int n, m;
int a[N], b[N], res[N];
int c[10][N];
Query q[N];
BinaryIndexedTree<int> bit[10];

inline int get_dth(const int &x, const int &d) {
  return x/pw10[d]%10;
}

inline void init(const int &d) {
  for (int i = 1; i <= n; ++i) {
    c[b[i]][i] = 0;
    b[i] = get_dth(a[i], d);
    c[b[i]][i] = 1;
  }
  for (int i = 0; i < 10; ++i) bit[i].init(n, c[i]);
}

inline void update(const int &x, const int &y, const int &d) {
  c[b[x]][x] = 0;
  bit[b[x]].add(x, -1);
  b[x] = get_dth(y, d);
  c[b[x]][x] = 1;
  bit[b[x]].add(x, 1);
}

inline void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int i = 1; i <= m; ++i) {
    getchar();
    scanf("%c", &q[i].op);
    if (q[i].op == 'Q') {
      scanf("%d%d%d%d", &q[i].l, &q[i].r, &q[i].d, &q[i].p);
      --q[i].d;
    } else {
      scanf("%d%d", &q[i].l, &q[i].r);
    }
  }
  for (int d = 0; d < 10; ++d) {
    init(d);
    for (int i = 1; i <= m; ++i) {
      if (q[i].op == 'Q') {
        if (q[i].d == d) res[i] = bit[q[i].p].query(q[i].l, q[i].r);
      } else {
        update(q[i].l, q[i].r, d);
      }
    }
  }
  for (int i = 1; i <= m; ++i) {
    if (q[i].op == 'Q') printf("%d\n", res[i]);
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}