/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 13:30:24
 * @LastEditTime: 2021-07-04 13:33:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 4e5+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

int n;
int a[N], e[N], vis[N];

void dfs(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  dfs(e[x]);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, b; i <= n; ++i) {
    cin >> b;
    e[a[i]] = b;
    vis[i] = 0;
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) if (!vis[i]) {
    dfs(i);
    ++cnt;
  }
  cout << qpow(2, cnt) << '\n';
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