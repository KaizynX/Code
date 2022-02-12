/*
 * @Author: Kaizyn
 * @Date: 2022-02-12 23:15:30
 * @LastEditTime: 2022-02-12 23:36:58
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
const int N = 2e2 + 7;
const int M = 1e4 + 7;

int n;
int a[N];
bitset<M> dp[N];

inline void solve() {
  cin >> n;
  ll sum = 0, ans = INF, base = 0;
  for (int i = 1; i <= n * 2; ++i) {
    cin >> a[i];
    sum += a[i];
    dp[i].reset();
    base += a[i] * a[i] * (n - 2ll);
  }
  dp[0][0] = 1;
  for (int i = 1; i <= n * 2; ++i) {
    for (int j = 1; j <= i && j <= n; ++j) {
      dp[j] |= dp[j - 1] <<  a[i];
    }
  }
  for (ll i = 1; i <= sum / 2; ++i) {
    if (dp[n][i]) {
      ans = min(ans, i * i + (sum - i) * (sum - i));
    }
  }
  ans = ans + base;
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