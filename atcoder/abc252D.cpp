/*
 * @Author: Kaizyn
 * @Date: 2022-05-21 19:58:11
 * @LastEditTime: 2022-05-21 20:05:21
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
const int N = 2e5 + 7;

int n;
int t1[N];
ll t2[N], t3[N];

inline void solve() {
  cin >> n;
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    ++t1[a];
  }
  ll sum2 = 0, sum3 = 0;
  for (int i = 1; i <= 200000; ++i) {
    if (t1[i] == 0) continue;
    t2[i] = (n - t1[i]) * t1[i];
    sum2 += t2[i];
  }
  #ifdef DEBUG
  orzarr(t2 + 1, 10);
  #endif
  for (int i = 1; i <= 200000; ++i) {
    if (t1[i] == 0) continue;
    t3[i] = (sum2 - 2 * t2[i]) * t1[i];
    sum3 += t3[i];
  }
  cout << sum3 / 6 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}