/*
 * @Author: Kaizyn
 * @Date: 2021-11-27 21:16:17
 * @LastEditTime: 2021-11-27 21:30:39
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
const int N = 2e5+7;

int n;
int a[N], b[N], ok[2][2][2][2];
ll dp[N][2][2];

template <typename T>
void update(T &x, const T &y) {
  if (x == -1 || y < x) x = y;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
  memset(ok, 0x01, sizeof ok);
  ok[0][0][0][0] = ok[0][0][1][0] = ok[0][1][0][0] = ok[0][1][0][1] = 0;
  ll ans = -1;
  for (int a1 : {0, 1}) for (int b1 : {0, 1}) {
    memset(dp, -1, sizeof dp);
    dp[0][b1][a1] = a1*a[1]+b1*b[1];
    for (int i = 2; i <= n; ++i) {
      for (int ai : {0, 1}) for (int bi : {0, 1})
      for (int aj : {0, 1}) for (int bj : {0, 1}) if (ok[bi][ai][bj][aj]) {
        update(dp[i][aj][bj], dp[i-1][ai][bi]+aj*a[i]+bj*b[i]);
      }
    }
    for (int ai : {0, 1}) for (int bi : {0, 1}) if (ok[bi][ai][b1][a1]) {
      update(ans, dp[n][ai][bi]);
    }
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