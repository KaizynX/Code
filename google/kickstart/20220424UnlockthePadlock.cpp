/*
 * @Author: Kaizyn
 * @Date: 2022-04-24 07:21:19
 * @LastEditTime: 2022-04-24 07:50:08
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
const int N = 4e2 + 7;

int n, d;
int a[N];
ll dp[2][N][N];

int calc(int cur, int last) {
  #ifdef DEBUG
  // printf("calc(%d,%d)=%d\n", cur, last, min((cur - last + d) % d, d - (cur - last + d) % d));
  #endif
  cur = (cur - last + d) % d;
  return min(cur, d - cur);
}

template <typename T>
void MIN(T &x, T y) {
  if (x > y) x = y;
}

inline ll solve() {
  scanf("%d%d", &n, &d);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", a + i);
  }
  n = unique(a + 1, a + n + 1) - a - 1;
  dp[0][1][n] = calc(a[1], 0);
  dp[1][1][n] = calc(a[n], 0);
  for (int len = n - 1; len; --len) {
    for (int l = 1, r = len; r <= n; ++l, ++r) {
      dp[0][l][r] = dp[1][l][r] = inf<ll>;
      if (l > 1) {
        MIN(dp[0][l][r], dp[0][l - 1][r] + calc(a[l], a[l - 1]));
        MIN(dp[1][l][r], dp[0][l - 1][r] + calc(a[r], a[l - 1]));
      }
      if (r < n) {
        MIN(dp[0][l][r], dp[1][l][r + 1] + calc(a[l], a[r + 1]));
        MIN(dp[1][l][r], dp[1][l][r + 1] + calc(a[r], a[r + 1]));
      }
    }
  }
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      cout << pii{dp[0][i][j], dp[1][i][j]} << " \n"[j == n];
    }
  }
  #endif
  ll ans = dp[0][1][1];
  for (int i = 1; i <= n; ++i) {
    ans = min({ans, dp[0][i][i], dp[1][i][i]});
  }
  return ans;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("Case #%d: %lld\n", t, solve());
  }
  return 0;
}