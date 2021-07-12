/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 15:44:25
 * @LastEditTime: 2021-07-12 15:49:52
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

int n;
ll a[N], b[N], s[N], f[N];

inline ll w(int k, int i) {
  return a[k]+s[i-k];
}

void DP(int l, int r, int k_l, int k_r) {
  int mid = (l + r) / 2, k = k_l;
  // 求状态f[mid]的最优决策点
  for (int i = k_l; i <= min(k_r, mid - 1); ++i)
    if (w(i, mid) > w(k, mid)) k = i;
  f[mid] = w(k, mid);
  // 根据决策单调性得出左右两部分的决策区间，递归处理
  if (l < mid) DP(l, mid - 1, k_l, k);
  if (r > mid) DP(mid + 1, r, k, k_r);
}

inline void solve() {
  cin >> n;
  for (int i = 0; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  sort(b+1, b+n+1);
  reverse(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) s[i] = s[i-1]+b[i];
  DP(1, n, 0, n-1);
  for (int i = 1; i <= n; ++i) cout << f[i] << " \n"[i==n];
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