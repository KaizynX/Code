/*
 * @Author: Kaizyn
 * @Date: 2022-05-14 20:23:07
 * @LastEditTime: 2022-05-14 20:25:44
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
const int N = 3e5 + 7;

int n;
int a[N];
ll dp[2][2][N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  dp[0][0][1] = 0;
  dp[0][1][1] = inf<ll>;
  dp[1][1][1] = a[1];
  dp[1][0][1] = inf<ll>;
  for (int i = 2; i <= n; ++i) {
    for (int _ : {0, 1}) {
      dp[_][0][i] = dp[_][1][i - 1];
      dp[_][1][i] = min(dp[_][0][i - 1], dp[_][1][i - 1]) + a[i];
    }
  }
  cout << min({dp[0][1][n], dp[1][0][n], dp[1][1][n]}) << '\n';
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