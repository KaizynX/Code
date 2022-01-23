/*
 * @Author: Kaizyn
 * @Date: 2022-01-23 20:07:39
 * @LastEditTime: 2022-01-23 20:37:38
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
const int N = 16;

int n;
int a[N][N];
int dp[1<<N];

inline void solve() {
  cin >> n;
  for (int i = 0; i < 2 * n; ++i) {
    for (int j = i + 1; j < 2 * n; ++j) {
      cin >> a[i][j];
    }
  }
  for (int b = 0; b < 1 << (2 * n); ++b) {
    if (__builtin_popcount(b) & 1) continue;
    for (int i = 0; i < 2 * n; ++i) if ((b >> i) & 1) {
      for (int j = i + 1; j < 2 * n; ++j) if ((b >> j) & 1) {
        dp[b] = max(dp[b], dp[b ^ (1 << i) ^ (1 << j)] ^ a[i][j]);
      }
    }
  }
  cout << dp[(1 << (2 * n)) - 1] << '\n';
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