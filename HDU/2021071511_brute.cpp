/*
 * @Author: Kaizyn
 * @Date: 2021-07-15 15:03:34
 * @LastEditTime: 2021-07-15 15:43:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = (1<<18)+7;

int n;
int a[N], b[N];
ll c[N];

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i]; ;
  ll ans = 0;
  for (int k = 0; k < n; ++k) {
    c[k] = -INF;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i&j) >= k) c[k] = max(c[k], 1ll*a[i]*b[j]);
      }
    }
    cout << c[k] << " \n"[k==n-1];
    ans = (ans+c[k])%MOD;
  }
  cout << (ans+MOD)%MOD << '\n';
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
1
3
-6 2 -6
-6 -7 2

18
*/