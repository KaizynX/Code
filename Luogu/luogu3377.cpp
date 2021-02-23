/*
 * @Author: Kaizyn
 * @Date: 2021-02-22 13:42:13
 * @LastEditTime: 2021-02-22 14:02:55
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

template <typename T> struct Tree { // 左偏树|可并堆
#define ls tr[x].son[0]
#define rs tr[x].son[1]
  struct TreeNode {
    T val;
    int dis, rt, son[2];
  };
  vector<TreeNode> tr;
  template <typename TT> void build(TT a[], int n) {
    tr.resize(n+1);
    tr[0].dis = -1;
    for (int i = 1; i <= n; ++i) {
      tr[i].val = a[i];
      tr[i].rt = i;
    }
  }
  int get(int x) {
    return tr[x].rt == x ? x : tr[x].rt = get(tr[x].rt);
  }
  void merge(int x, int y) {
    if (tr[x].val == -1 || tr[y].val == -1) return;
    x = get(x); y = get(y);
    if (x != y) tr[x].rt = tr[y].rt = _merge(x, y);
  }
  int _merge(int x, int y) {
    if (!x || !y) return x+y;
    if (tr[x].val > tr[y].val || (tr[x].val == tr[y].val && x > y)) swap(x, y);
    rs = _merge(rs, y);
    if(tr[ls].dis < tr[rs].dis) swap(ls, rs);
    tr[ls].rt = tr[rs].rt = tr[x].rt = x;
    tr[x].dis = tr[rs].dis+1;
    return x;
  }
  T pop(int x) {
    if (tr[x].val == -1) return -1;
    x = get(x);
    T res = tr[x].val;
    tr[x].val = -1;
    tr[ls].rt = ls;
    tr[rs].rt = rs;
    tr[x].rt = _merge(ls, rs);
    return res;
  }
#undef ls
#undef rs
};

int n, m;
int a[N];
Tree<int> tree;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  tree.build(a, n);
  for (int i = 1, op, x, y; i <= m; ++i) {
    cin >> op;
    if (op == 1) {
      cin >> x >> y;
      tree.merge(x, y);
    } else {
      cin >> x;
      cout << tree.pop(x) << '\n';
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}