/*
 * @Author: Kaizyn
 * @Date: 2021-02-05 23:23:47
 * @LastEditTime: 2021-02-06 15:24:57
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

int n;
int a[N], b[N], dp[N], l[N], r[N], cnt[N], rk[N];
BinaryIndexedTree<int> tree;

inline int solve() { // max books don't need to move
  tree.init(n);
  memset(dp+1, dp+n+1, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) {
    l[i] = n+1;
    r[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    l[a[i]] = min(l[a[i]], i);
    r[a[i]] = max(r[a[i]], i);
  }
  iota(rk+1, rk+n+1, 1);
  sort(rk+1, rk+n+1, [&](int x, int y) {
    return r[x] < r[y];
  });
  for (int _ = 1, i; _ <= n; ++_) {
    i = rk[_];
    if (l[i] > r[i]) continue;
    dp[r[i]] = max(dp[r[i]], tree.query(l[i]-1)+cnt[i]);
    tree.add(r[i], dp[r[i]]);
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << "(" << l[i] << "," << r[i] << ")" << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << dp[i] << " \n"[i==n];
  #endif
  return tree.query(n);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i], ++cnt[a[i]];
  int res = n-solve(), p = 1, base = 0;
  memcpy(b+1, a+1, sizeof(int)*n);
  fill(a+1, a+n+1, b[n]);
  for (int i = 1; i <= n; ++i) {
    if (b[i] == a[n]) continue;
    a[p++] = b[i];
  }
  base = n-p+1;
  for (int i = n; b[i] == a[n]; --i) --base;
  res = min(res, n-solve()+base);
  cout << res << '\n';
  return 0;
}
/*
100
7 4 5 5 10 10 5 8 5 7 4 5 4 6 8 8 2 6 3 3 10 7 10 8 6 2 7 3 9 7 7 2 4 5 2 4 9 5 10 1 10 5 10 4 1 3 4 2 6 9 9 9 10 6 2 5 6 1 8 10 4 10 3 4 10 5 5 4 10 4 5 3 7 10 2 7 3 6 9 6 1 6 5 5 4 6 6 4 4 1 5 1 6 6 6 8 8 6 2 6

77
*/