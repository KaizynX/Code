/*
 * @Author: Kaizyn
 * @Date: 2021-03-10 20:48:50
 * @LastEditTime: 2021-03-10 20:57:57
 */
#include <bits/stdc++.h>

#define DEBUG

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
int p[N], xl[N], xr[N], yl[N], yr[N];
set<int> sy;

// x go small

inline bool check(int x, int y) {
  if (x < y) return xl[x] > max(yr[y], 1);
  else return xr[x] > max(yl[y], 1);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  int mx = 0, mt = 0;
  for (int i = 2; i <= n; ++i) {
    if (p[i] > p[i-1]) {
      xl[i] = xl[i-1]+1;
    } else {
      yl[i] = yl[i-1]+1;
    }
  }
  for (int i = n-1; i; --i) {
    if (p[i] > p[i+1]) {
      xr[i] = xr[i+1]+1;
      mx = max(mx, xr[i]);
    } else {
      yr[i] = yr[i+1]+1;
    }
  }
  for (int i = 1; i <= n; ++i) {
      if (max(xl[i], xr[i]) == mx) {
        ++mt;
      } else {
        mx = max(xl[i], xr[i]);
        mt = 1;
      }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << xl[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << xr[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << yl[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << yr[i] << " \n"[i==n];
  #endif
  int res = 0;
  for (int i = 2; i < n; ++i) if (xl[i] && xr[i] && max(xl[i], xr[i]) == mx) {
    if (check(i, i-1) && check(i, i+1)) {
      int v1 = xl[i], v2 = xr[i];
      if (v1 > v2) swap(v1, v2);
      if (v1 > v2-(v2%2==0)) ++res;
    }
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}