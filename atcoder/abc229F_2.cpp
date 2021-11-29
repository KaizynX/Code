/*
 * @Author: Kaizyn
 * @Date: 2021-11-27 21:30:34
 * @LastEditTime: 2021-11-27 21:41:46
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
// const int INF = 0x3f3f3f3f;
const ll INF = 1e18;
const int N = 2e5+7;

int n;
int a[N], b[N];
ll dp[N][2];

template <typename T>
void update(T &x, const T &y) {
  // if (x == -1 || y < x) x = y;
  if (y < x) x = y;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  ll ans = INF;
  // color of 0 is 0
  for (int c1 : {0, 1}) {
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = a[1];
    dp[1][1] = 0;
    dp[1][c1^1] = INF;
    for (int i = 2; i <= n; ++i) {
      dp[i][0] = min(dp[i-1][0]+b[i-1], dp[i-1][1])+a[i];
      dp[i][1] = min(dp[i-1][0], dp[i-1][1]+b[i-1]);
      // cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }
    ans = min({ans, dp[n][0]+(0 == c1)*b[n], dp[n][1]+(1 == c1)*b[n]});
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