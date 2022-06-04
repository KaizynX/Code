/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 19:58:36
 * @LastEditTime: 2022-06-04 20:06:42
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
int cnt[N];
int a[N];

inline void solve() {
  cin >> n;
  iota(a + 1, a + n + 1, 1);
  for (int i = 2; i <= n; ++i) {
    for (int j = i; j <= n; j += i) {
      int k = 0;
      while (a[j] % i == 0) {
        ++k;
        a[j] /= i;
      }
      if (k & 1) a[j] *= i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ++cnt[a[i]];
  }
  #ifdef DEBUG
  // orzarr(cnt + 1, n);
  #endif
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += 1ll * cnt[i] * cnt[i];
  }
  cout << ans << '\n';
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