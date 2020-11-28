/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 15:02:01
 * @LastEditTime: 2020-10-25 15:21:16
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n, m;
int a[N];
vector<int> p[N];

struct SegmentTree {
  struct TreeNode {
    int l, r, v, z;
  } tr[N<<2];
  void push_up(int i) {
    tr[i].v = min(tr[i<<1].v, tr[i<<1|1].v);
  }
  void push_down(int i) {
    if (!tr[i].z) return;
    tr[i<<1].z = max(tr[i<<1].z, tr[i].z);
    tr[i<<1|1].z = max(tr[i<<1|1].z, tr[i].z);
    tr[i<<1].v = max(tr[i<<1].v, tr[i<<1].z-tr[i<<1].r);
    tr[i<<1|1].v = max(tr[i<<1|1].v, tr[i<<1|1].z-tr[i<<1|1].r);
    tr[i].z = 0;
  }
  void build(int l, int r, int i = 1) {
    tr[i].l = l; tr[i].r = r;
    tr[i].v = tr[i].z = 0;
    if (l == r) return;
    int mid = (l+r)>>1;
    build(l, mid, i<<1);
    build(mid+1, r, i<<1|1);
  }
  void update(int l, int r, int v, int i = 1) {
    #ifdef DEBUG
    cout << "tree.update:" << l << " " << r << " " << v << endl;
    #endif
    if (tr[i].l >= l && tr[i].r <= r) {
      tr[i].z = max(tr[i].z, v);
      tr[i].v = max(tr[i].v, v-tr[i].r);
      return;
    }
    push_down(i);
    int mid = (tr[i].l+tr[i].r)>>1;
    if (l <= mid) update(l, r, v, i<<1);
    if (r >  mid) update(l, r, v, i<<1|1);
    push_up(i);
  }
  int query() {
    return tr[1].v;
  }
} tree;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) p[i].emplace_back(0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  tree.build(1, n);
  for (int i = 1; i <= m; ++i) {
    // tree.update(1, p[i].front(), p[i].front());
    for (int j = 1; j < (int)p[i].size(); ++j)
      tree.update(p[i][j-1]+1, p[i][j], p[i][j]);
    if (p[i].back() < n)
      tree.update(p[i].back()+1, n, INF);
    cout << tree.query()+1 << " \n"[i==m];
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}