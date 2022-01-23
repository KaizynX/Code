/*
 * @Author: Kaizyn
 * @Date: 2022-01-23 20:20:42
 * @LastEditTime: 2022-01-23 20:29:04
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
const double eps = 1e-4;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5 + 7;

int n;
int a[N];

double solve1() {
  static double dp[N];
  double l = 1, r = 1e9, mid;
  while (r - l > eps) {
    mid = (l + r) / 2;
    dp[1] = a[1] - mid;
    for (int i = 2; i <= n; ++i) {
      dp[i] = max(dp[i - 2], dp[i - 1]) + a[i] - mid;
    }
    if (max(dp[n], dp[n - 1]) >= 0) l = mid;
    else r = mid - eps;
  }
  return (l + r) / 2;
}

int solve2() {
  static int dp[N];
  int l = 1, r = 1e9, mid;
  while (l < r) {
    mid = (l + r + 1) / 2;
    dp[1] = a[1] >= mid ? 1 : -1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = max(dp[i - 2], dp[i - 1]) + (a[i] >= mid ? 1 : -1);
    }
    if (max(dp[n], dp[n - 1]) > 0) l = mid;
    else r = mid - 1;
  }
  return l;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cout << solve1() << '\n';
  cout << solve2() << '\n';
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