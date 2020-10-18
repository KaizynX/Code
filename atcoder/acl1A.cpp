/*
 * @Author: Kaizyn
 * @Date: 2020-10-04 19:53:49
 * @LastEditTime: 2020-10-04 20:09:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

struct Node {
  int x, y, id;
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
int res[N];
Node a[N];
BinaryIndexedTree<int> tree;

void discrete() {
  static int d[N], m;
  for (int i = 1; i <= n; ++i) d[i] = a[i].x;
  sort(d+1, d+n+1);
  m = unique(d+1, d+n+1)-d;
  for (int i = 1; i <= n; ++i)
    a[i].x = lower_bound(d+1, d+m, a[i].x)-d;
  for (int i = 1; i <= n; ++i) d[i] = a[i].y;
  sort(d+1, d+n+1);
  m = unique(d+1, d+n+1)-d;
  for (int i = 1; i <= n; ++i)
    a[i].y = lower_bound(d+1, d+m, a[i].y)-d;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
    a[i].id = i;
  }
  // discrete();
  sort(a+1, a+n+1, [](Node n1, Node n2) {
    return n1.x < n2.x;
  });
  tree.init(n);
  for (int i = 1; i <= n; ++i) {
    res[a[i].id] += tree.query(1, a[i].y-1);
    tree.add(a[i].y, 1);
  }
  tree.init(n);
  for (int i = n; i; --i) {
    res[a[i].id] += tree.query(a[i].y+1, n);
    tree.add(a[i].y, 1);
  }
  for (int i = 1; i <= n; ++i) cout << res[i]+1 << endl;
  return 0;
}