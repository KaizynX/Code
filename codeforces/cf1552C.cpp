/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 22:30:18
 * @LastEditTime: 2021-07-25 23:15:51
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;

template <typename T>
struct BinaryIndexedTree {
  int n;
  vector<T> tr;
  void init(const int &n) { this->n = n; tr = vector<T>(n+1, 0); }
  void add(const int &x, const T &v) { for (int i = x; i <= n; i += i&-i) tr[i] += v; }
  void add(const int &x, const int &y, const T &v) { add(x, v); add(y+1, -v); }
  T query(const int &x) { T res = 0; for (int i = x ; i; i -= i&-i) res += tr[i]; return res; }
  T query(const int &x, const int &y) { return query(y)-query(x-1); }
};

int n, k;
int vis[N], a[N];
BinaryIndexedTree<int> tree;

int check(int i, int j) {
  return (i < j) == (vis[i] < vis[j]);
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= 2*n; ++i) vis[i] = 0;
  for (int i = 1, x, y; i <= k; ++i) {
    cin >> x >> y;
    vis[x] = y;
    vis[y] = x;
  }
  int m = 0;
  for (int i = 1; i <= 2*n; ++i) {
    if (vis[i]) continue;
    a[++m] = i;
  }
  for (int i = 1; i <= m/2; ++i) {
    vis[a[i]] = a[i+m/2];
    vis[a[i+m/2]] = a[i];
  }
  #ifdef DEBUG
  for (int i = 1; i <= 2*n; ++i) {
    if (vis[i] < i) continue;
    cout << i << ' ' << vis[i] << '\n';
  }
  #endif
  // tree.init(2*n);
  int res = 0;
  for (int i = 1; i <= 2*n; ++i) {
    if (vis[i] < i) continue;
    for (int j = 1; j < i; ++j) {
      if (vis[j] < j) continue;
      res += check(i, j);
      #ifdef DEBUG
      printf("(%d,%d)(%d,%d)=%d\n", i, vis[i], j, vis[j], check(i, j));
      #endif
    }
    // res += tree.query(vis[i]);
    // tree.add(vis[i], 1);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
10
4 2
1 2
3 8
*/