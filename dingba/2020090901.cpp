/*
 * @Author: Kaizyn
 * @Date: 2020-09-09 18:50:04
 * @LastEditTime: 2020-09-09 20:30:58
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

long long n, m;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> m;
  n %= MOD;
  long long res = (qpow(n, m)-n*qpow(n-1, m-1)%MOD+MOD)%MOD;
  cout << res << endl;
  return 0;
}