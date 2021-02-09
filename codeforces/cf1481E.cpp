/*
 * @Author: Kaizyn
 * @Date: 2021-02-05 22:33:00
 * @LastEditTime: 2021-02-05 23:22:28
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  T tr[N];
  BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
  void init(const int &_n) { n = _n; clear(); }
  void clear() { memset(tr+1, 0, sizeof(T)*n); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] = max(tr[i], v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res = max(res, tr[i]); return res; }
};

struct Node {
  int l, r;
  bool operator <(const Node &b) const {
    return pii{l, r} < pii{b.l, b.r};
  }
  int len() const {
    return r-l+1;
  }
};

int n;
int a[N], dp[N];
Node b[N];
BinaryIndexedTree<int> tree;

inline int solve() {
  for (int i = 1; i <= n; ++i) b[i] = Node{n+1, 0};
  for (int i = 1; i <= n; ++i) {
    b[a[i]].l = min(b[a[i]].l, i);
    b[a[i]].r = max(b[a[i]].r, i);
  }
  sort(b+1, b+n+1);
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << "(" << b[i].l << "," << b[i].r << ")" << " \n"[i==n];
  #endif
  tree.init(n);
  for (int i = 1; i <= n && b[i].r; ++i) {
    dp[b[i].r] = max(dp[b[i].r], tree.query(b[i].l-1)+b[i].len());
    tree.add(b[i].r, dp[b[i].r]);
  }
  return tree.query(n);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  int res = n-solve(), p = 1, base = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[n]) continue;
    a[p++] = a[i];
  }
  base = n-p+1;
  for (int i = n; a[i] == a[n]; --i) --base;
  for (int i = p; i <= n; ++i) a[i] = p;
  res = min(res, n-solve()+base);
  cout << res << '\n';
  return 0;
}