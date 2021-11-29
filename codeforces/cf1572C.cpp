/*
 * @Author: Kaizyn
 * @Date: 2021-11-29 17:44:54
 * @LastEditTime: 2021-11-29 17:55:00
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
const int N = 3e3+7;

int n;
int a[N];
int dp[N][N];
vector<int> p[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  for (int len = 2; len <= n; ++len) {
    for (int l = 1, r; (r = l+len-1) <= n; ++l) {
      dp[l][r] = dp[l+1][r];
      for (int k : p[a[l]]) if (k > l && k <= r) {
        dp[l][r] = max(dp[l][r], 1+dp[l+1][k-1]+dp[k][r]);
      }
    }
  }
  cout << n-1-dp[1][n] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) p[i].clear();
  }
  return 0;
}