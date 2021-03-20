/*
 * @Author: Kaizyn
 * @Date: 2021-03-20 22:04:09
 * @LastEditTime: 2021-03-20 22:50:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, m, k;
int res[N];

struct DSU {
  int n;
  vector<int> fa, rk; // [1, n] partner, [n+1, 2n] enemy
  stack<pair<int&, int>> stk;
  void init(int n) {
    this->n = n;
    stk = stack<pair<int&, int>>();
    fa = rk = vector<int>(2*n+1, 0);
    iota(fa.begin(), fa.end(), 0);
  }
  int& operator [] (int i) { return fa[get(i)]; }
  int get(int s) { while (s != fa[s]) s = fa[s]; return s; }
  void undo() { stk.top().first = stk.top().second; stk.pop(); }
  void merge(int x, int y) {
    x = get(x); y = get(y);
    if (x == y) return;
    if (rk[x] > rk[y]) swap(x, y);
    stk.push({fa[x], fa[x]});
    stk.push({rk[y], rk[y]});
    fa[x] = y;
    rk[y] += rk[x] == rk[y];
  }
  bool update(int x, int y) {
    if (get(x) == get(y)) return false;
    merge(x+n, y);
    merge(x, y+n);
    return true;
  }
};

DSU dsu;

template <typename T>
struct SegmentTree {
  struct TreeNode {
    int l, r;
    vector<T> infos;
  } tr[N<<2];
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    tr[i].infos = vector<T>();
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void insert(int l, int r, const T &info, int i = 1) {
    if (tr[i].l >= l && tr[i].r <= r) {
      tr[i].infos.emplace_back(info);
      return;
    }
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) insert(l, r, info, i<<1);
    if (r >  mid) insert(l, r, info, i<<1|1);
  }
  void work(int i = 1) {
    int sz = dsu.stk.size(), flag = 1;
    for (auto &p : tr[i].infos) {
      if (!dsu.update(p.first, p.second)) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      if (tr[i].l == tr[i].r) res[tr[i].l] = 1;
      else work(i<<1), work(i<<1|1);
    }
    while (sz != (int)dsu.stk.size()) dsu.undo();
  }
};

SegmentTree<pii> tree;

signed main() {
  scanf("%d%d%d", &n, &m, &k);
  tree.build(1, k);
  for (int i = 1, u, v, l, r; i <= m; ++i) {
    scanf("%d%d%d%d", &u, &v, &l, &r);
    if (l < r) tree.insert(l+1, r, {u, v});
  }
  dsu.init(n);
  tree.work();
  for (int i = 1; i <= k; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}