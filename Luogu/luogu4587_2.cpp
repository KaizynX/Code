/*
 * @Author: Kaizyn
 * @Date: 2021-06-09 23:33:01
 * @LastEditTime: 2021-06-10 22:01:11
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

template <class T>
class PersistantSegmentTree {
 public:
  void init(int n) {
    tot = 0;
    this->n = n;
    rt = vector<int>(1, 0);
    tr = vector<TreeNode>(1, TreeNode{0, 0, 0});
  }
  void update(int cur, int pre, int k, T v = 1) {
    rt.resize(cur+1); // assert rt.size()+1 <= cur
    rt[cur] = update(rt[pre], 1, n, k, v);
  }
  int update(int pre, int l, int r, int k, T v) {
    int cur = ++tot; // assert tot == tr.size()
    tr.emplace_back(tr[pre]);
    tr[cur].sum += v;
    if (l == r) return cur;
    int mid = (l+r)>>1;
    if (k <= mid) tr[cur].lc = update(tr[pre].lc, l, mid, k, v);
    else tr[cur].rc = update(tr[pre].rc, mid+1, r, k, v);
    return cur;
  }
  T query(int l, int r, int ql, int qr) {
    return query(rt[l-1], rt[r], 1, n, ql, qr);
  }
  // [u, v] 段 [ql, qr] 区间和
  T query(int u, int v, int l, int r, int ql, int qr) {
    if (!u && !v) return 0;
    if (l >= ql && r <= qr) return tr[v].sum-tr[u].sum;
    int mid = (l+r)>>1;
    if (qr <= mid) return query(tr[u].lc, tr[v].lc, l, mid, ql, qr);
    if (ql >  mid) return query(tr[u].rc, tr[v].rc, mid+1, r, ql, qr);
    return query(tr[u].lc, tr[v].lc, l, mid, ql, qr)+query(tr[u].rc, tr[v].rc, mid+1, r, ql, qr);
  }
 private:
  struct TreeNode {
    int lc, rc;
    T sum;
  };
  int tot, n;
  vector<int> rt;
  vector<TreeNode> tr;
};

int n, m, q;
int a[N], d[N];
PersistantSegmentTree<int> tree;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  tree.init(1e9);
  for (int i = 1; i <= n; ++i) {
    tree.update(i, i-1, a[i], a[i]);
  }
  cin >> q;
  for (int i = 1, l, r, res; i <= q; ++i) {
    cin >> l >> r;
    res = 1;
    while (true) {
      int val = tree.query(l, r, 1, res);
      if (val >= res) res = val+1;
      else break;
    }
    cout << res << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}