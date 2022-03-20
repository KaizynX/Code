/*
 * @Author: Kaizyn
 * @Date: 2022-03-20 13:25:46
 * @LastEditTime: 2022-03-20 13:55:09
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
// const int N = ;

using ld = long double;
#define double ld
constexpr ll INF = 2e18;
ll n, k, ans_int;

ll f(ll x, double p) {
  // y * (ans_int + p)
  if (INF / ans_int < x) return INF;
  return x * ans_int + static_cast<ll>(round(x * p));
}

ll binary_int() {
  ll l = 2, r = n, mid;
  while (l < r) {
    mid = (l + r) / 2;

    ll x = 1;
    int flag = 0;
    for (int i = 1; i <= k; ++i) {
      if (INF / mid < x || x * mid >= n) {
        flag = 1;
        break;
      }
      x *= mid;
    }

    if (flag) r = mid;
    else l = mid + 1;
  }
  return l;
}

double binary_double() {
  double l = 0, r = 1, mid;
  for (int i = 1; i <= 1000; ++i) {
    mid = (l + r) / 2;

    ll x = 1;
    int flag = 0;
    for (int i = 1; i <= k; ++i) {
      x = f(x, mid);
      if (x >= n) {
        flag = 1;
        break;
      }
    }

    if (flag) r = mid;
    else l = mid;
  }
  return (l + r) / 2;
}

inline void solve() {
  scanf("%lld%lld", &n, &k);
  if (n == 1) return printf("0.5\n"), void();
  if (k == 1) return printf("%lld\n", n), void();
  if (k >= 102) return printf("1.5\n"), void();
  ans_int = binary_int() - 1;
  #ifdef DEBUG
  // orz(ans_int);
  #endif
  double ans = ans_int + binary_double();
  printf("%.10Lf\n", ans);
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
1000000000000000000
*/