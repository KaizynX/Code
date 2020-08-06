/*
 * @Author: Kaizyn
 * @Date: 2020-08-04 21:13:19
 * @LastEditTime: 2020-08-04 21:46:52
 */
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

template <typename T>
struct SegmentTree { // 区间加减区间和
  struct TreeNode {
    int l, r;
    TreeNode *ls, *rs;
    T val, lazy;
    TreeNode() { ls = rs = nullptr; }
    TreeNode(const int &_l, const int &_r, const T &_val = 0)
        : l(_l), r(_r), val(_val) {
      ls = rs = nullptr;
      lazy = 0;
    }
    int len() const { return r-l+1; }
  };
  TreeNode *root;
  void clear(TreeNode *rt) {
    if (!rt) return;
    clear(rt->ls);
    clear(rt->rs);
    delete rt;
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
    if (rt->l >= l && rt->r <= r) return rt->val;
    push_down(rt);
    int mid = (rt->l+rt->r)>>1;
    if (l <= mid && !rt->ls) rt->ls = new TreeNode(rt->l, mid);
    if (r >  mid && !rt->rs) rt->rs = new TreeNode(mid+1, rt->r);
    if (r <= mid) return query(l, r, rt->ls);
    if (l >  mid) return query(l, r, rt->rs);
    return query(l, r, rt->ls)+query(l, r, rt->rs);
  }
};

int n, m;
int a[N];
SegmentTree<long long> ST;

int main()
{
  scanf("%d%d", &n, &m);
  ST.build(n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a+i);
    ST.update(i, a[i]);
  }
  for (int i = 1, op, x, y; i <= m; ++i) {
    scanf("%d%d%d", &op, &x, &y);
    if (op == 1) {
      long long k;
      scanf("%lld", &k);
      ST.add(x, y, k);
    } else {
      printf("%lld\n", ST.query(x, y));
    }
  }
  return 0;
}
