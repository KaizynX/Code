/*
 * @Author: Kaizyn
 * @Date: 2022-04-24 07:09:18
 * @LastEditTime: 2022-04-24 07:14:34
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

ll n;

int check(ll x) {
  string s = to_string(x);
  string t = s;
  reverse(t.begin(), t.end());
  if (s == t) cout << s << '\n';
  return s == t;
}

inline ll solve() {
  scanf("%lld", &n);
  ll ans = 0;
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i) continue;
    ans += check(i);
    if (i != n / i) ans += check(n / i);
  }
  return ans;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("Case #%d: %lld\n", t, solve());
  }
  return 0;
}