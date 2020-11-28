/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 12:32:50
 * @LastEditTime: 2020-10-25 12:42:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

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

struct Node {
  int l, r;
  long long v;
};

int n, m, r, c;
int a[N][N];
BinaryIndexedTree<long long> tree;
vector<Node> upd[N];

inline bool solve() {
  scanf("%d %d %d %d", &n, &m, &r, &c);
  for (int i = 1; i <= n; ++i) {
    upd[i].clear();
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  tree.init(m);
  for (int i = 1; i <= n; ++i) {
    for (Node &nd : upd[i]) tree.add(nd.l, nd.r, nd.v);
    for (int j = 1; j <= m; ++j) {
      long long v = a[i][j]+tree.query(j);
      if (v == 0) continue;
      if (v < 0 || j+c-1 > m || i+r-1 > n) return false;
      tree.add(j, j+c-1, -v);
      upd[i+r].push_back(Node{j, j+c-1, v});
    }
  }
  return true;
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    puts(solve() ? "^_^" : "QAQ");
  }
  return 0;
}