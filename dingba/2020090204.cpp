/*
 * @Author: Kaizyn
 * @Date: 2020-09-02 19:00:20
 * @LastEditTime: 2020-09-03 14:49:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e4+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

long long n;
int k;
int a[N];

int brute() {
  long long res = 0;
  sort(a+1, a+k+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= k; ++j) {
      (res += 1ll*a[j]*qpow(i, a[j])) %= MOD;
    }
  }
  return res;
}

inline void solve() {
  cin >> k >> n;
  for (int i = 1; i <= k; ++i) cin >> a[i];
  cout << brute() << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}