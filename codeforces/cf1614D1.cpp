/*
 * @Author: Kaizyn
 * @Date: 2021-11-26 19:04:41
 * @LastEditTime: 2021-11-26 20:23:22
 */
#include <bits/stdc++.h>

// #define DEBUG

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
const int N = 1e5+7;
#ifdef DEBUG
const int A = 6;
#else
const int A = 5e6;
#endif

int n;
int a[A+1], t[A+1];
ll dp[A+1];

inline void solve() {
  cin >> n;
  for (int i = 1, b; i <= n; ++i) {
    cin >> b;
    ++a[b];
  }
  ll ans = 0;
  for (int i = A; i; --i) {
    for (int j = i; j <= A; j += i) t[i] += a[j];
    dp[i] = 1ll*t[i]*i;
    for (int j = i+i; j <= A; j += i) {
      dp[i] = max(dp[i], dp[j]+(ll)(t[i]-t[j])*i);
    }
    ans = max(ans, dp[i]);
  }
  #ifdef DEBUG
  orzarr(t, 7);
  orzarr(dp, 7);
  #endif
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