/*
 * @Author: Kaizyn
 * @Date: 2020-10-15 22:42:17
 * @LastEditTime: 2020-10-15 23:42:13
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
struct SegmentTree { // 区间加减区间和
  struct TreeNode {
    int l, r;
    TreeNode *ls, *rs;
    T val;
    TreeNode() { ls = rs = nullptr; }
    TreeNode(const int &_l, const int &_r, const T &_val = 0)
        : l(_l), r(_r), val(_val) {
      ls = rs = nullptr;
    }
  };
  TreeNode *root;
  void clear(TreeNode *rt) {
    if (!rt) return;
    clear(rt->ls);
    clear(rt->rs);
    delete rt;
    rt = nullptr;
  }
  void build(const int &n) {
    clear(root);
    root = new TreeNode(1, n);
  }
  void push_up(TreeNode *rt) {
    rt->val = (rt->ls ? rt->ls->val : 0)+(rt->rs ? rt->rs->val : 0);
  }
  void update(const int &x, const T &k) { update(x, k, root); }
  void update(const int &x, const T &k, TreeNode *rt) {
    if (rt->l == rt->r) return rt->val += k, void(); // here add or modify
    int mid = (rt->l+rt->r)>>1;
    if (x <= mid) update(x, k, rt->ls ? rt->ls : rt->ls = new TreeNode(rt->l, mid));
    else update(x, k, rt->rs ? rt->rs : rt->rs = new TreeNode(mid+1, rt->r));
    push_up(rt);
  }
  T query(const int &x) { return query(x, x, root); }
  T query(const int &l, const int &r) { return query(l, r, root); }
  T query(const int &l, const int &r, TreeNode *rt) {
    if (!rt) return 0;
    if (rt->l >= l && rt->r <= r) return rt->val;
    int mid = (rt->l+rt->r)>>1;
    if (r <= mid) return query(l, r, rt->ls);
    if (l >  mid) return query(l, r, rt->rs);
    return query(l, r, rt->ls)+query(l, r, rt->rs);
  }
};

template <typename T>
struct SegSegTree { // 线段树套线段树
  struct TreeNode {
    int l, r;
    TreeNode *ls, *rs;
    SegmentTree<T> v;
    TreeNode() { ls = rs = nullptr; v. build(); }
    TreeNode(const int &_l, const int &_r, const T &_val = 0)
        : l(_l), r(_r) {
      ls = rs = nullptr;
      v.build();
    }
  };
  TreeNode *root;
  void clear(TreeNode *rt) {
    if (!rt) return;
    clear(rt->ls);
    clear(rt->rs);
    delete rt;
    rt = nullptr;
  }
  void build(const int &n) {
    clear(root);
    root = new TreeNode(1, n);
  }
  void push_up(TreeNode *rt) {
    rt->val = (rt->ls ? rt->ls->val : 0)+(rt->rs ? rt->rs->val : 0);
  }
  void push_down(TreeNode *rt) {
    if (!rt->lazy) return;
    int mid = (rt->l+rt->r)>>1;
    if (!rt->ls) rt->ls = new TreeNode(rt->l, mid);
    if (!rt->rs) rt->rs = new TreeNode(mid+1, rt->r);
    rt->ls->lazy += rt->lazy;
    rt->ls->val += rt->lazy*rt->ls->len();
    rt->rs->lazy += rt->lazy;
    rt->rs->val += rt->lazy*rt->rs->len();
    rt->lazy = 0;
  }
  void update(const int &x, const T &k) { update(x, k, root); }
  void update(const int &x, const T &k, TreeNode *rt) {
    if (rt->l == x && rt->r == x) return rt->val = k, void();
    push_down(rt);
    int mid = (rt->l+rt->r)>>1;
    if (x <= mid) update(x, k, rt->ls ? rt->ls : rt->ls = new TreeNode(rt->l, mid));
    else update(x, k, rt->rs ? rt->rs : rt->rs = new TreeNode(mid+1, rt->r));
    push_up(rt);
  }
  void add(const int &x, const T &k) { add(x, x, k, root); }
  void add(const int &l, const int &r, const T &k) { add(l, r, k, root); }
  void add(const int &l, const int &r, const T &k, TreeNode *rt) {
    if (rt->l >= l && rt->r <= r) {
      rt->val += rt->len()*k;
      rt->lazy += k;
      return;
    }
    push_down(rt);
    int mid = (rt->l+rt->r)>>1;
    if (l <= mid) add(l, r, k, rt->ls ? rt->ls : rt->ls = new TreeNode(rt->l, mid));
    if (r >  mid) add(l, r, k, rt->rs ? rt->rs : rt->rs = new TreeNode(mid+1, rt->r));
    push_up(rt);
  }
  T query(const int &x) { return query(x, x, root); }
  T query(const int &l, const int &r) { return query(l, r, root); }
  T query(const int &l, const int &r, TreeNode *rt) {
    if (!rt) return 0;
    if (rt->l >= l && rt->r <= r) return rt->val;
    push_down(rt);
    int mid = (rt->l+rt->r)>>1;
    if (r <= mid) return query(l, r, rt->ls);
    if (l >  mid) return query(l, r, rt->rs);
    return query(l, r, rt->ls)+query(l, r, rt->rs);
  }
}

int n, k;
int a[N], b[N], c[N], rk[N], f[N];

void discrete(int *arr) {
  static int d[N], m;
  memcpy(d+1, arr+1, sizeof(int)*n);
  sort(d+1, d+n+1);
  m = unique(d+1, d+n+1)-d;
  for (int i = 1; i <= n; ++i)
    arr[i] = lower_bound(d+1, d+m, arr[i])-d;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
    rk[i] = i;
  }
  discrete(a);
  discrete(b);
  discrete(c);
  sort(rk+1, rk+n+1, [](int x, int y) {
    return a[x] < a[y];
  });
  for (int i = 1, j; i <= n; ++i) {
    j = i;
    while (j <= n && a[rk[j]] == i) {
      ++j;
    }
  }
  return 0;
}