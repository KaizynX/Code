/*
 * @Author: Kaizyn
 * @Date: 2021-01-09 22:03:46
 * @LastEditTime: 2021-01-09 22:06:10
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
const int N = 2e4+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

ll n;
int m;
int a[N], b[N];

inline void solve() {
  cin >> n >> m;
  if (n == 1) {
    cout << 10/m%m << endl;
    return;
  }
  if (m == 1) {
    cout << 0 << endl;
    return;
  }
  int r = 1, k;
  for (k = 1; k == 1 || r != 1; ++k) {
    a[k] = (a[k-1]*10+r*10/m)%m;
    r = r*10%m;
    if (k > 10004) while(1);
  }
  --k;
  // r == 10^k%m
  for (int i = 1; i <= m; ++i) {
    b[i] = (b[i-1]*r+a[k])%m;
  }
  // assert((b[m]*r+a[k])%m == b[1]);
  int res = (b[n/k%m]*qpow(10, n%k, m)+a[n%k])%m;
  cout << res << endl;
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