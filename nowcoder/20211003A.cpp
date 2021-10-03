/*
 * @Author: Kaizyn
 * @Date: 2021-10-03 12:12:36
 * @LastEditTime: 2021-10-03 12:34:42
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
const int N = 37;

int n;
short b[N][5], w[4];
short dp[N][N][N][N][N];
char last[N][N][N][N][N];

template <typename T>
void update(T &x, T y) {
  if (y > x) x = y;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < 5; ++j) cin >> b[i][j];
  for (int i = 0; i < 4; ++i) cin >> w[i];
  for (int i = 1; i <= n; ++i) {
    short *a = b[i];
    memcpy(dp[i], dp[i-1], sizeof dp[i]);
    memcpy(last[i], last[i-1], sizeof last[i]);
    for (int i0 = w[0]; i0 >= a[0]; --i0)
    for (int i1 = w[1]; i1 >= a[1]; --i1)
    for (int i2 = w[2]; i2 >= a[2]; --i2)
    for (int i3 = w[3]; i3 >= a[3]; --i3) {
      short tmp = dp[i-1][i0-a[0]][i1-a[1]][i2-a[2]][i3-a[3]]+a[4];
      short &cur = dp[i][i0][i1][i2][i3];
      if (tmp > cur) {
        cur = tmp;
        last[i][i0][i1][i2][i3] = i;
      }
    }
  }
  // cout << dp[w[0]][w[1]][w[2]][w[3]] << '\n';
  vector<int> ans;
  for (int i = last[n][w[0]][w[1]][w[2]][w[3]]; i; i = last[i-1][w[0]][w[1]][w[2]][w[3]]) {
    ans.emplace_back(i);
    for (int j = 0; j < 4; ++j) w[j] -= b[i][j];
  }
  cout << ans.size() << '\n';
  for (int i : ans) cout << i-1 << ' ';
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