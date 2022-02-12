/*
 * @Author: Kaizyn
 * @Date: 2022-02-13 00:50:31
 * @LastEditTime: 2022-02-13 01:01:43
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
const int N = 2e5 + 7;

int n;
int h[N];
ll dp[N][2];
vector<int> e[N];
multiset<int> st;

ll dfs(int u, int fa, int tag) {
  ;
}

void dfs(int u, int fa) {
  int mx0 = 0;
  dp[u][0] = 0;
  for (auto v : e[u]) if (v != fa) {
    dfs(v, u);
    mx0 = max(mx, dp[v][0]);
    dp[u][0] += dp[v][0];
  }
  if (h[u] > mx0) dp[u][0] += h[u] - mx0;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  dfs(rt, 0);
  int rt = max_element(h + 1, h + n + 1) - h;
  for (auto i : e[rt]) {
    dfs(i, rt, h[rt]);
  }
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