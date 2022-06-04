/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 19:28:03
 * @LastEditTime: 2022-06-05 00:33:25
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
// template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

int n;
int a[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  int mn = a[1], mx = 0;
  for (int i = 2; i <= n; ++i) {
    if (a[i] >= mn) {
      mx = max(mx, a[i]);
    }
    mn = min(mn, a[i]);
  }
  if (mx == 0) return cout << "0\n", void();
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += a[i] <= mx;
  }
  cout << ans - 1 << '\n';
  /*
  int ans = 0;
  st.clear();
  for (int i = n; i; --i) {
    auto it = st.upper_bound(a[i]);
    if (it != st.end()) {
      st.erase(it);
      ++ans;
    } else {
      st.insert(a[i]);
    }
  }
  cout << ans << '\n';
  */
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