/*
 * @Author: Kaizyn
 * @Date: 2021-10-02 14:56:10
 * @LastEditTime: 2021-10-02 15:45:39
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
const int N = 4e5+7;

int n;
int a[N];
vector<int> e[N];
ll bb[N][5][5]; // bb[i][j][k] choose j's dp[1] and k links
ll dp[2][N][4]; // dp[0] any, dp[1][i] i'th can extend

template <typename T>
void update(T &x, T y) {
  if (y > x) x = y;
}

void dfs(int u, int fa = 0) {
  memset(bb[u], -1, sizeof bb[u]);
  bb[u][0][0] = 0;
  for (int v : e[u]) if (v != fa) {
    dfs(v, u);
    for (int i = 4; i >= 0; --i)
    for (int j = 4; j; --j)
    for (int k = min(3, j); k; --k) {
      if (~bb[u][i][j-k]) update(bb[u][i][j], bb[u][i][j-k]+dp[0][v][k]);
      if (i && ~bb[u][i-1][j-k]) update(bb[u][i][j], bb[u][i-1][j-k]+dp[1][v][k]);
    }
  }
  /*
  for (int i = 0; i <= 3; ++i) {
    for (int j = 1; j <= 4; ++j) {
      update(bb[u][i][j], bb[u][i][j-1]);
    }
  }
  */
#ifdef DEBUG
  for (int i = 0; i <= 4; ++i) {
    for (int j = 1; j <= 4; ++j) {
      printf("%lld ", bb[u][i][j]);
    }
    printf(",");
  }
  printf("bb[%d]\n", u);
#endif
  for (int i = 1; i <= 3; ++i) {
    dp[1][u][i] = max({bb[u][0][i-1], bb[u][1][i], bb[u][2][i], bb[u][3][i]})+a[u];
    dp[0][u][i] = max({bb[u][0][i], dp[1][u][i], bb[u][2][i+1]+a[u], bb[u][3][i+1]+a[u], bb[u][4][i+1]+a[u]});
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  dfs(1);
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    printf("dp[%d]=[", i);
    for (int j = 1; j <= 3; ++j) printf("%lld ", dp[0][i][j]);
    printf("],[");
    for (int j = 1; j <= 3; ++j) printf("%lld ", dp[1][i][j]);
    printf("]\n");
  }
#endif
  cout << dp[0][1][3] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  // memset(bb, -1, sizeof bb);
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}