/*
 * @Author: Kaizyn
 * @Date: 2021-09-17 10:09:18
 * @LastEditTime: 2021-09-17 10:17:12
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 6e3+7;

int n, m;
int dp[2][N];

void update(int &x, int y) {
  if (y > x) x = y;
}

inline void solve() {
  scanf("%d%d", &n, &m);
  memset(dp[0], -1, sizeof(int)*(m+1));
  dp[0][0] = 0;
  int ans = 0;
  for (int i = 1, a, b, c, d; i <= n; ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    memset(dp[i&1], -1, sizeof(int)*(m+1));
    for (int j = a; j <= m; ++j) if (~dp[~i&1][j-a])
      update(dp[i&1][j], dp[~i&1][j-a]+b);
    for (int j = c; j <= m; ++j) if (~dp[~i&1][j-c])
      update(dp[i&1][j], dp[~i&1][j-c]+d);
    for (int j = 1; j <= m; ++j) update(ans, dp[i&1][j]);
  }
  printf("%d\n", ans);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}