/*
 * @Author: Kaizyn
 * @Date: 2021-08-10 12:21:36
 * @LastEditTime: 2021-08-11 13:17:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n;
int a[N], vis[N];
ll sum[N];
int cnt[N], fa[N];

int getf(int s) { return s == fa[s] ? s : fa[s] = getf(fa[s]); }
bool dsu_merge(int x, int y) { // merge x to y
  x = getf(x); y = getf(y);
  if (x == y) return 0;
  cnt[y] += cnt[x];
  sum[y] += cnt[x];
  fa[x] = y;
  return true;
}

inline bool solve() {
  cin >> n;
  int eq = 1;
  iota(fa+1, fa+n+1, 1);
  fill(cnt+1, cnt+n+1, 1);
  memset(vis+1, 0, sizeof(int)*n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (i > 1) eq &= a[i] == a[i-1];
    sum[i] = a[i];
  }
  if (eq) return 1;
  for (int i = 1; i <= n; ++i) {
    if (vis[a[i]]) return 0;
    vis[a[i]] = 1;
    dsu_merge(i, a[i]);
  }
  ll s = 0, c = 0;
  for (int i = 1; i <= n; ++i) if (getf(i) == i) {
    if (s == 0) {
      s = sum[i], c = cnt[i];
    } else {
      if (s*cnt[i] != sum[i]*c) return false;
    }
  }
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}