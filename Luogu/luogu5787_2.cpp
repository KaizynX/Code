/*
 * @Author: Kaizyn
 * @Date: 2021-03-12 19:50:13
 * @LastEditTime: 2021-03-12 19:55:49
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
int col[N];
vector<int> e[N];

bool black_white(int u) {
  for (int &v : e[u]) {
    if (~col[v]) {
      if (col[u] == col[v]) return false;
    } else {
      col[v] = col[u]^1;
      black_white(v);
    }
  }
  return true;
}

bool check(const vector<pii> &edges) {
  for (auto &p : edges) {
    int u = p.first;
    int v = p.second;
    col[u] = col[v] = -1;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  bool flag = true;
  for (auto &p : edges) {
    int u = p.first;
    if (col[u] == -1) {
      col[u] = 0;
      if (!black_white(u)) {
        flag = false;
        break;
      }
    }
  }
  for (auto &p : edges) {
    int u = p.first;
    int v = p.second;
    e[u].clear();
    e[v].clear();
  }
  return flag;
}

template <typename T>
struct SegmentTree {
  struct TreeNode {
    int l, r;
    vector<T> infos;
  } tr[N<<2];
  vector<T> Info;
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
  void collect(int x, int i = 1) {
    Info.insert(Info.end(), tr[i].infos.begin(), tr[i].infos.end());
    if (tr[i].l == tr[i].r) return;
    int mid = (tr[i].l+tr[i].r)>>1;
    if (x <= mid) collect(x, i<<1);
    if (x >  mid) collect(x, i<<1|1);
  }
  bool query(int x) {
    Info.clear();
    collect(x);
    return check(Info);
  }
};

SegmentTree<pii> tree;

signed main() {
  scanf("%d%d%d", &n, &m, &k);
  tree.build(1, n);
  for (int i = 1, u, v, l, r; i <= m; ++i) {
    scanf("%d%d%d%d", &u, &v, &l, &r);
    tree.insert(l+1, r, {u, v});
  }
  for (int i = 1; i <= k; ++i) {
    puts(tree.query(i) ? "Yes" : "No");
  }
  return 0;
}