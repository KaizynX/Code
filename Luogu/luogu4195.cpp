/*
 * @Author: Kaizyn
 * @Date: 2021-02-21 16:59:00
 * @LastEditTime: 2021-02-21 19:05:49
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
// const int N = ;

template <typename T>
T exgcd(const T a, const T b, T &x, T &y) {
  if (!b) return x = 1, y = 0, a;
  T d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

namespace EXBSGS {

inline ll BSGS(ll a, ll b, ll mod, ll qaq){
  unordered_map<ll, int> H; H.clear();
  ll Q, p = ceil(sqrt(mod)), x, y; 
  exgcd(qaq, mod, x, y), b = (b * x % mod + mod) % mod, 
  Q = qpow(a, p, mod), exgcd(Q, mod, x, y), Q = (x % mod + mod) % mod ;
  for (ll i = 1, j = 0 ; j <= p ; ++ j, i = i * a % mod)  if (!H.count(i)) H[i] = j ;
  for (ll i = b, j = 0 ; j <= p ; ++ j, i = i * Q % mod)  if (H[i]) return j * p + H[i];
  return -1 ;
}

inline ll exBSGS(ll N, ll P, ll M){
  ll qaq = 1, k = 0, qwq = 1; 
  if (M == 1) return 0 ; 
  while ((qwq = __gcd(N, P)) > 1) {
    if (M%qwq) return -1 ;
    ++k, M /= qwq, P /= qwq, qaq = qaq*(N/qwq)%P ;
    if (qaq == M) return k ;
  }
  return (qwq = BSGS(N, M, P, qaq)) == -1 ? -1 : qwq+k ;
}

} using EXBSGS::exBSGS;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int a, p, b;
  while (cin >> a >> p >> b && a|p|b) {
    ll res = exBSGS(a, p, b);
    if (~res) cout << res << '\n';
    else cout << "No Solution\n";
  }
  return 0;
}