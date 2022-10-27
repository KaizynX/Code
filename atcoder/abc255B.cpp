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
const int N = 1e3 + 7;

int k, n;
int a[N];
ll x[N], y[N];

double dis(int i, int j) {
  return sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> x[i] >> y[i];
  double ans = 0;
  for (int i = 1; i <= n; ++i) {
    double cur = 1e18;
    for (int j = 1; j <= k; ++j) {
      cur = min(cur, dis(i, a[j]));
    }
    if (cur == 0.0) continue;
    ans = max(ans, cur);
  }
  // cout << ans << '\n';
  printf("%.6f\n", ans);
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