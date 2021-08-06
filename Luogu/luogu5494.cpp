/*
 * @Author: Kaizyn
 * @Date: 2021-08-06 14:53:50
 * @LastEditTime: 2021-08-06 17:20:26
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
#define log(x) (31-__builtin_clz(x))
const int N = 2e5+7;
const int NLOG = N*(log(N)+2);

template <typename T>
struct Tree {
  int tot, lc[NLOG], rc[NLOG];
  T tr[NLOG];
  T giao(const T &x, const T &y) { return x+y; }
  void push_up(int i) { tr[i] = giao(tr[lc[i]], tr[rc[i]]); }
  int new_node(T v = 0) {
    assert(++tot < NLOG);
    lc[tot] = rc[tot] = 0;
    tr[tot] = v;
    return tot;
  }
  void add(int x, T v, int l, int r, int &i) {
    if (!i) i = new_node();
    if (l == r) return tr[i] += v, void();
    int mid = (l+r)>>1;
    if (x <= mid) add(x, v, l, mid, lc[i]);
    else add(x, v, mid+1, r, rc[i]);
    push_up(i);
  }
  void merge(int l, int r, int &x, int &y) { // merge y to x
    if (!x || !y) return x += y, void();
    if (l == r) return tr[x] += tr[y], void();
    int mid = (l+r)>>1;
    merge(l, mid, lc[x], lc[y]);
    merge(mid+1, r, rc[x], rc[y]);
    push_up(x); // del(y);
  }
  void split(int L, int R, int l, int r, int &x, int &y) { //split x [L, R] to y
    if (!x) return;
    if (L <= l && r <= R) return y = x, x = 0, void();
    if (!y) y = new_node();
    int mid = (l+r)>>1;
    if (L <= mid) split(L, R, l, mid, lc[x], lc[y]);
    if (R >  mid) split(L, R, mid+1, r, rc[x], rc[y]);
    push_up(x); push_up(y);
  }
  T query_sum(int L, int R, int l, int r, int i) {
    if (!i) return 0;
    if (L <= l && r <= R) return tr[i];
    int mid = (l+r)>>1;
    if (R <= mid) return query_sum(L, R, l, mid, lc[i]);
    if (L >  mid) return query_sum(L, R, mid+1, r, rc[i]);
    return query_sum(L, R, l, mid, lc[i])+query_sum(L, R, mid+1, r, rc[i]);
  }
  int query_kth(int k, int l, int r, int i) {
    if (l == r) return l;
    int mid = (l+r)>>1;
    if (k <= tr[lc[i]]) return query_kth(k, l, mid, lc[i]);
    return query_kth(k-tr[lc[i]], mid+1, r, rc[i]);
  }
};

int n, m;
int root[N];
Tree<ll> tree;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n >> m;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    tree.add(i, a, 1, n, root[1]);
  }
  for (int i = 1, opt, p, x, y, sz = 1; i <= m; ++i) {
    cin >> opt >> p >> x;
    if (opt == 0) {
      cin >> y;
      tree.split(x, y, 1, n, root[p], root[++sz]);
    } else if (opt == 1) {
      tree.merge(1, n, root[p], root[x]);
    } else if (opt == 2) {
      cin >> y;
      tree.add(y, x, 1, n, root[p]);
    } else if (opt == 3) {
      cin >> y;
      cout << tree.query_sum(x, y, 1, n, root[p]) << '\n';
    } else {
      cout << (x <= tree.tr[root[p]] ? tree.query_kth(x, 1, n, root[p]) : -1) << '\n';
    }
  }
  return 0;
}