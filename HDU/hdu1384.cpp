/*
 * @Author: Kaizyn
 * @Date: 2020-05-14 14:09:36
 * @LastEditTime: 2020-05-14 14:24:32
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

struct Node {
  int l, r, c;
  friend bool operator < (const Node &lhs, const Node &rhs) {
    return lhs.r < rhs.r;
  }
  friend istream& operator >> (istream &is, Node &nd) {
    return is >> nd.l >> nd.r >> nd.c;
  }
};

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
};

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
};

int n, m;
Node a[N];
DSU dsu;
BinaryIndexedTree<int> bit;

inline void solve() {
  m = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    m = max(m, a[i].r);
  }
  dsu.init(m);
  bit.init(m);
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = dsu[a[i].r], cnt = bit.query(a[i].l, a[i].r);
        cnt < a[i].c; ++cnt, j = dsu[j]) {
      bit.add(j, 1);
      dsu.merge(j, j-1);
    }
  }
  cout << bit.query(1, m) << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n) solve();
  return 0;
}