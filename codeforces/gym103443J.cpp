/*
 * @Author: Kaizyn
 * @Date: 2022-03-23 15:35:16
 * @LastEditTime: 2022-03-23 15:58:11
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
const int N = 1e6 + 7;

int n, m, p;

inline void solve() {
  cin >> n >> m >> p;
  for (int i = 1, a; i <= m; ++i) cin >> a;
  int s1 = m, u1 = p - m, u2 = n - p - 1;
  ll val0 = s1 + u1 * 2 + u2 * 2;
  ll val1 = 1 + u2 + (s1 - 1) * 2 + u1 * 3;
  ll vals1 = 1 + (s1 - 1) * 2 + u1 * 3 + u2 * 3;
  ll valu1 = 2 + s1 * 3 + (u1 - 1) * 4 + u2 * 4;
  ll valu2 = 1 + 2 + (u2 - 1) * 2 + (s1 - 1) * 3 + u1 * 4;
  #ifdef DEBUG
  orz(val0);
  orz(val1);
  orz(vals1);
  orz(valu1);
  orz(valu2);
  #endif
  ll ans = val0 + val1 + (s1 - 1) * vals1 + u1 * valu1 + u2 * valu2;
  cout << ans << '\n';
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