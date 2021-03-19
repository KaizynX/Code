/*
 * @Author: Kaizyn
 * @Date: 2021-03-19 21:34:20
 * @LastEditTime: 2021-03-19 23:41:57
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
  vector<int> flag;
  vector<int> ptn, enm, siz; // ptntner, enemy
  stack<pair<vector<int>::iterator, int>> stk;
  void init(int n) {
    flag = vector<int>(1, 1);
    stk = stack<pair<vector<int>::iterator, int>>();
    siz = vector<int>(n+1, 1);
    ptn = enm = vector<int>(n+1, 0);
    iota(ptn.begin(), ptn.end(), 0);
  }
  int get(int s) { while (s != ptn[s]) s = ptn[s]; return s; }
  void merge(int x, int y) {
    x = get(x); y = get(y);
    if (siz[x] > siz[y]) swap(x, y);
    stk.push({ptn.begin()+x, ptn[x]});
    stk.push({siz.begin()+y, siz[y]});
    ptn[x] = y;
    siz[y] += x;
  }
  int update(int x, int y) {
    if(!enm[x] && !enm[y]) { // set this two to oppsite
      stk.push({enm.begin()+x, enm[x]});
      stk.push({enm.begin()+y, enm[y]});
      enm[x] = y;
      enm[y] = x;
      return 2;
    } else if(!enm[x] && enm[y]) { // set x to y's enemy
      merge(x, enm[y]);
      stk.push({enm.begin()+x, enm[x]});
      enm[x] = get(y);
      return 3;
    } else if(enm[x] && !enm[y]) {
      merge(y, enm[x]);
      stk.push({enm.begin()+y, enm[y]});
      enm[y] = get(x);
      return 3;
    } else if(get(enm[x]) != get(enm[y])) { // connect(enm[x],ptn[y]) (enm[y],ptn[x])
      merge(y, enm[x]);
      merge(x, enm[y]);
      return 4;
    } else {
      stk.push({flag.begin(), flag[0]});
      flag[0] = 0;
      return 1;
    }
    return 2;
  }
  bool undo() {
    if (stk.empty()) return false;
    *stk.top().first = stk.top().second;
    stk.pop();
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
    int cnt = 0;
    for (auto &p : tr[i].infos) cnt += dsu.update(p.first, p.second);
    if (tr[i].l == tr[i].r) res[tr[i].l] = dsu.flag[0];
    else work(i<<1), work(i<<1|1);
    while (cnt--) dsu.undo();
  }
};

SegmentTree<pii> tree;

signed main() {
  scanf("%d%d%d", &n, &m, &k);
  tree.build(1, k);
  for (int i = 1, u, v, l, r; i <= m; ++i) {
    scanf("%d%d%d%d", &u, &v, &l, &r);
    tree.insert(l+1, r, {u, v});
  }
  dsu.init(n);
  tree.work();
  for (int i = 1; i <= k; ++i) {
    puts(res[i] ? "Yes" : "No");
  }
  return 0;
}