/*
 * @Author: Kaizyn
 * @Date: 2022-02-27 20:13:58
 * @LastEditTime: 2022-02-27 20:16:16
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
const int N = 2e5 + 7;

int n;
int a[N];
vector<int> stk;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  auto st = min_element(a + 1, a + n + 1);
  rotate(a + 1, st, a + n + 1);
  stk.emplace_back(0);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (a[i] > stk.back()) ans += a[i] - stk.back();
    while (stk.size() && stk.back() <= a[i]) stk.pop_back();
    stk.emplace_back(a[i]);
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