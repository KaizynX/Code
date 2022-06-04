/*
 * @Author: Kaizyn
 * @Date: 2022-06-03 23:02:18
 * @LastEditTime: 2022-06-03 23:22:10
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

int n, k;
int a[N];
ll s[N];

ll calc(int beg, int len) {
  return (beg + len - 1ll + beg) * len / 2;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    s[i] = s[i - 1] + a[i];
  }
  ll ans = 0;
  if (n == 1) {
    ans = s[n] + k - 1;
  } else if (k >= n) {
    ans = s[n] + 1ll * k * n;
    /*
    k = k % (n - 1) + 1;
    // ans -= k * (k + 1ll) / 2 + (2 * k + n + k - 1ll) * (n - k) / 2;
    ans -= calc(1, k) + calc(2 * k, n - k);
    */
   ans -= calc(1, n);
  } else {
    for (int i = k; i <= n; ++i) {
      ans = max(ans, s[i] - s[i - k]);
    }
    ans += calc(1, k - 1);
  }
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