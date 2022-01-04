/*
 * @Author: Kaizyn
 * @Date: 2022-01-04 00:45:22
 * @LastEditTime: 2022-01-04 00:47:06
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
const int N = 5e2+7;

int n;
int c[N][N];

inline void solve() {
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= 2 * n; ++i) {
    for (int j = 1; j <= 2 * n; ++j) {
      cin >> c[i][j];
      if (i > n && j > n) ans += c[i][j];
    }
  }
  ans += min({c[1][n + 1],
              c[1][2 * n],
              c[n][n + 1],
              c[n][2 * n],
              c[n + 1][1],
              c[n + 1][n],
              c[2 * n][1],
              c[2 * n][n]
              });
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