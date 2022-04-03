/*
 * @Author: Kaizyn
 * @Date: 2022-04-03 13:01:46
 * @LastEditTime: 2022-04-03 13:26:24
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
const int N = 100;

inline void solve() {
  int X, T;
  scanf("%d%d", &X, &T);
  // sleep T/3
  double ans = T * 200 / 3.0;
  // sleep [T/6, T/3]
  // ans = max(ans, (T - t) * (1.0 - (1.0 - X / 100.0) / (T / 3.0 - T / 6.0) * (T / 3.0 - t));
  double k = (100 - X) / (T / 6.0);
  double t0 = T / 3.0 - 100.0 / k;
  double tm = (t0 + T) / 2.0;
  if (T / 6.0 <= tm && tm <= T / 3.0) {
    ans = max(ans, (T - tm) * (tm - t0) * k);
  }
  #ifdef DEBUG
  orz(k);
  orz(t0);
  orz(tm);
  #endif
  // sleep [0, T/6]
  // ans = max(ans, (T - t) * (t * 6.0 / T) * (X / 100.0));
  // ans = max(ans, (T - t) * t * (6.0 / T) * (X / 100.0));
  // top at T / 2, top at T / 6
  ans = max(ans, T * X * 5 / 6.0);
  printf("%.8f\n", ans);
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