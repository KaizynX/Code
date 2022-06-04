/*
 * @Author: Kaizyn
 * @Date: 2022-06-03 22:41:12
 * @LastEditTime: 2022-06-03 22:46:46
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
// const int N = ;

inline void solve() {
  int x;
  cin >> x;
  int y = x & - x;
  if (__builtin_popcount(x) == 1) {
    if (x == 1) y |= 2;
    else y |= 1;
  }
  /*
  for (int i = 0, f0 = 1, f1 = 1; i <= 30; ++i) {
    if ((x >> i) & 1) {
      if (f1) {
        y |= 1 << i;
        f1 = 0;
      }
    } else {
      if (f0) {
        y |= 1 << i;
        f0 = 0;
      }
    }
  }
  */
  cout << y << '\n';
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