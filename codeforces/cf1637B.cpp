/*
 * @Author: Kaizyn
 * @Date: 2022-02-12 22:41:14
 * @LastEditTime: 2022-02-12 22:56:57
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
const int N = 1e2 + 7;

int n;
int a[N], dp[N][N], mex[N][N];
set<int> st1, st2;

void init() {
  st2.clear();
  for (int i = 0; i < N; ++i) {
    st1.insert(i);
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    init();
    for (int j = i; j <= n; ++j) {
      if (a[j] < N && !st2.count(a[j])) {
        st2.insert(a[j]);
        st1.erase(a[j]);
      }
      dp[i][j] = *st1.begin() + 1;
    }
  }
  ll ans = 0;
  for (int len = 1; len <= n; ++len) {
    for (int l = 1, r; (r = l + len - 1) <= n; ++l) {
      for (int k = l; k < r; ++k) {
        dp[l][r] = max(dp[l][r], dp[l][k] + dp[k + 1][r]);
      }
      #ifdef DEBUG
      printf("dp[%d][%d]=%d\n", l, r, dp[l][r]);
      #endif
      ans += dp[l][r];
    }
  }
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