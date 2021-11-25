/*
 * @Author: Kaizyn
 * @Date: 2021-11-26 00:09:54
 * @LastEditTime: 2021-11-26 00:21:11
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
const int N = 2e5+7;

int n, k, ans;
int x[N], vis[N], tag[N];
vector<int> e[N], stk;

void dfs1(int u, int fa = 0) {
  stk.emplace_back(u);
  if (vis[u]) tag[stk[stk.size()/2]] = 1;
  for (int v : e[u]) if (v != fa) {
    dfs1(v, u);
  }
  stk.pop_back();
}

void dfs2(int u, int fa = 0) {
  if (tag[u]) return ++ans, void();
  if (u != 1 && e[u].size() == 1u) ans = -INF;
  for (int v : e[u]) if (v != fa) {
    dfs2(v, u);
  }
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= k; ++i) {
    cin >> x[i];
    vis[x[i]] = 1;
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  ans = 0;
  dfs1(1);
  dfs2(1);
  #ifdef DEBUG
  orzarr(tag+1, n);
  #endif
  cout << max(-1, ans) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= n; ++i) {
      vis[i] = tag[i] = 0;
      e[i].clear();
    }
  }
  return 0;
}