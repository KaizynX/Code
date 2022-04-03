/*
 * @Author: Kaizyn
 * @Date: 2022-03-23 14:30:53
 * @LastEditTime: 2022-03-23 14:50:23
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
const int N = 1e2 + 7;
const int M = 10100 + 7;

int n;
int a[2][N];
// dp[][i][j] 选了i个是否能达到j的差值
bitset<M> dp[2][N];
ll sum[2];

inline void solve() {
  cin >> n;
  for (int _ : {0, 1}) {
    sum[_] = 0;
    for (int i = 0; i <= n; ++i) dp[_][i].reset();
    dp[_][0] = 1;
    for (int i = 1; i <= n; ++i) {
      cin >> a[_][i];
      sum[_] += a[_][i] * i;
      if (a[_][i] == _ + 1) for (int j = i; j; --j) {
        dp[_][j] |= dp[_][j - 1] << i;
      }
    }
  }
  ll dis = sum[1] - sum[0];
  if (dis < 0 || dis >= M) return cout << "-1\n", void();
  for (int t = 0; t <= n; ++t) {
    for (int i = 0; i <= dis; ++i) {
      if (dp[0][t][i] && dp[1][t][dis - i]) {
        cout << t << '\n';
        return;
      }
    }
  }
  cout << "-1\n";
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