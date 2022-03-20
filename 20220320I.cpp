/*
 * @Author: Kaizyn
 * @Date: 2022-03-20 12:49:59
 * @LastEditTime: 2022-03-20 13:21:47
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

ll n, k;
using ld = long double;
#define double ld

ll f(ll y, double p) {
	ld x = p * (ld)y;
  if (x > 2e18) return 2e18;
  return round(x);
}

bool check(double p) {
  ll x = 1;
  for (int i = 1; i <= k; ++i) {
    x = f(x, p);
    if (x >= n) return true;
  }
  return false;
}

inline void solve() {
  scanf("%lld%lld", &n, &k);
  if (n == 1) return printf("1\n"), void();
  if (k == 1) return printf("%lld\n", n), void();
  if (k >= 102) return printf("1.5\n"), void();
  double l = 1.5, r = n, mid;
  for (int i = 1; i <= 1000; ++i) {
    mid = (l + r) / 2;
    if (check(mid)) r = mid;
    else l = mid;
  }
  printf("%.10Lf\n", (l + r) / 2);
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