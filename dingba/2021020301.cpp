/*
 * @Author: Kaizyn
 * @Date: 2021-02-03 13:16:28
 * @LastEditTime: 2021-02-03 15:20:21
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
const int N = 2e5+7;

int n, m;
int vis[2][N];
ll cnt[2], val[2];

void fuck(int shit) {
  if (shit) return;
  while (1) {}
}

inline void solve() {
  cin >> n >> m;
  for (int _ = m, k; _; --_) {
    ll p;
    cin >> k >> p;
    fuck(k == 0 || k == 1);
    fuck(p >= 1 && p <= n);
    if (vis[k][p]) {
      cout << 0 << endl;
      continue;
    }
    if (k) { // col
      cout << (n-cnt[k])*p+(n-1ll)*n*n/2-val[k] << endl;
      vis[k][p] = 1;
      ++cnt[k^1];
      val[k^1] += p;
    } else { // row
      cout << (p-1ll)*(n-cnt[k])*n+(1ll+n)*n/2-val[k] << endl;
      vis[k][p] = 1;
      ++cnt[k^1];
      val[k^1] += (p-1ll)*n;
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