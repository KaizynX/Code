/*
 * @Author: Kaizyn
 * @Date: 2020-05-15 11:01:35
 * @LastEditTime: 2020-05-15 12:13:33
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

int n, m;
int a[N], b[N][10];
int c[10][10][N];
BinaryIndexedTree<int> bit[10][10];

inline void init() {
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      memset(c[i][j], 0, sizeof(int)*(n+1));
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 0, v = a[i]; j < 10; ++j, v /= 10) {
      b[i][j] = v%10;
      c[j][b[i][j]][i] = 1;
    }
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      bit[i][j].init(n, c[i][j]);
    }
  }
}

inline void update(const int &x, const int &y) {
  for (int i = 0; i < 10; ++i) {
    bit[i][b[x][i]].add(x, -1);
  }
  a[x] = y;
  for (int j = 0, v = a[x]; j < 10; ++j, v /= 10) {
    b[x][j] = v%10;
    bit[j][b[x][j]].add(x, 1);
  }
}

inline void solve() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  init();
  char op[10];
  for (int i = 1, l, r, d, p; i <= m; ++i) {
    scanf("%s", op);
    if (op[0] == 'Q') {
      scanf("%d %d %d %d", &l, &r, &d, &p);
      printf("%d\n", bit[d-1][p].query(l, r));
    } else {
      scanf("%d %d", &l, &r);
      update(l, r);
    }
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