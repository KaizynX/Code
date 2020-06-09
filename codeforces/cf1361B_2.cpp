/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 22:31:39
 * @LastEditTime: 2020-06-05 00:49:00
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, p;
int k[N];

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

inline void solve() {
  cin >> n >> p;
  for (int i = 1; i <= n; ++i) cin >> k[i];
  if (p == 1) return cout << n%2 << endl, void();
  long long tmp = 1, tk = 0;
  while (tmp <= n) tmp *= p, ++tk;
  sort(k+1, k+n+1);
  reverse(k+1, k+n+1);
  long long dif = 0;
  k[0] = k[1];
  for (int i = 1, flag = 1; i <= n; ++i) {
    if ((dif && k[i-1]-k[i] >= tk) || dif > n-i+1) flag = 0;
    (dif *= qpow(p, k[i-1]-k[i])) %= MOD;
    if (flag) dif = abs(dif-1);
    else dif = (dif-1+MOD)%MOD;
  }
  (dif *= qpow(p, k[n])) %= MOD;
  cout << dif << endl;
  // cout << (dif%MOD+MOD)%MOD << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}