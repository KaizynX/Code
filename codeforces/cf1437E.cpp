/*
 * @Author: Kaizyn
 * @Date: 2020-10-27 22:28:32
 * @LastEditTime: 2020-10-27 23:17:01
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

template <typename T>
struct SegmentTree { // 区间最值
  struct TreeNode {
    int l, r;
    TreeNode *ls, *rs;
    T val;
    TreeNode() { ls = rs = nullptr; }
    TreeNode(const int &_l, const int &_r, const T &_val = 0)
        : l(_l), r(_r), val(_val) {
      ls = rs = nullptr;
    }
    int len() const { return r-l+1; }
  };
  TreeNode *root;
  void clear(TreeNode *&rt) {
    if (!rt) return;
    clear(rt->ls);
    clear(rt->rs);
    delete rt;
    rt = nullptr;
  }
  void build(int l, int r) {
    clear(root);
    root = new TreeNode(l, r);
  }
  void push_up(TreeNode *rt) {
    rt->val = max((rt->ls ? rt->ls->val : 0), (rt->rs ? rt->rs->val : 0));
  }
  void update(const int &x, const T &k) { update(x, k, root); }
  void update(const int &x, const T &k, TreeNode *rt) {
    if (rt->l == x && rt->r == x) return rt->val = max(rt->val, k), void();
    int mid = (rt->l+rt->r)>>1;
    if (x <= mid) update(x, k, rt->ls ? rt->ls : rt->ls = new TreeNode(rt->l, mid));
    else update(x, k, rt->rs ? rt->rs : rt->rs = new TreeNode(mid+1, rt->r));
    push_up(rt);
  }
  T query(const int &x) { return query(x, x, root); }
  T query(const int &l, const int &r) { return query(l, r, root); }
  T query(const int &l, const int &r, TreeNode *rt) {
    if (rt->l >= l && rt->r <= r) return rt->val;
    int mid = (rt->l+rt->r)>>1;
    if (l <= mid && !rt->ls) rt->ls = new TreeNode(rt->l, mid);
    if (r >  mid && !rt->rs) rt->rs = new TreeNode(mid+1, rt->r);
    if (r <= mid) return query(l, r, rt->ls);
    if (l >  mid) return query(l, r, rt->rs);
    return max(query(l, r, rt->ls), query(l, r, rt->rs));
  }
};

int n, m;
int a[N], b[N];
SegmentTree<int> tree;

inline int solve(int l, int r) {
  int *aa = a+l, len = r-l-1, sz = a[r]-a[l]-len-1, res = 0;
  if (sz < 0) return -1;
  if (!len) return 0;
  tree.build(0, sz);
  tree.update(0, 0);
  for (int i = 1; i <= len; ++i) {
    int v = aa[i]-aa[0]-i;
    if (v < 0 || v > sz) continue;
    int dp = tree.query(0, v)+1;
    res = max(res, dp);
    tree.update(v, dp);
  }
  return res;
}

signed main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", a+i);
  for (int i = 1; i <= m; ++i) scanf("%d", b+i);

  a[0] = -n; b[0] = 0;
  a[n+1] = 1e9+n; b[m+1] = n+1;
  int res = m;
  for (int i = 0; i <= m; ++i) {
    int tmp = solve(b[i], b[i+1]);
    if (tmp == -1) return puts("-1"), 0;
    res += tmp;
  }
  printf("%d\n", n-res);
  return 0;
}