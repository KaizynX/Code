/*
 * @Author: Kaizyn
 * @Date: 2021-02-03 16:19:19
 * @LastEditTime: 2021-02-03 16:30:28
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

ll n, m;
int vis[2][N];
ll val[2], cnt[2];

inline void solve() {
  // cin >> n >> m;
  scanf("%lld %lld", &n, &m);
  ll base[2] = {(1ll+n)*n/2, (n-1ll)*n*n/2};
  for (int _ = m; _; --_) {
    ll k, p, res;
    // cin >> k >> p;
    scanf("%lld %lld", &k, &p);
    if (vis[k][p]) {
      res = 0;
    } else {
      if (k) { // col
        res = base[k]-val[k]+p*(n-cnt[k]);
        val[k^1] += p;
      } else { // row
        res = base[k]-val[k]+(p-1ll)*n*(n-cnt[k]);
        val[k^1] += (p-1ll)*n;
      }
      vis[k][p] = 1;
      ++cnt[k^1];
    }
    printf("%lld\n", res);
    // cout << res << endl;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}