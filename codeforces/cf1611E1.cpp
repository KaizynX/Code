/*
 * @Author: Kaizyn
 * @Date: 2021-11-25 23:37:56
 * @LastEditTime: 2021-11-26 00:01:56
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

int n, k;
int vis[N], d[N], g[N];
vector<int> e[N], f[N];
multiset<int> st[N];

int dfs1(int u, int fa = 0) {
  int val = vis[u] ? 0 : n;
  f[u].resize(e[u].size());
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    if (v == fa) continue;
    d[v] = d[u]+1;
    f[u][i] = dfs1(v, u)+1;
    val = min(val, f[u][i]);
  }
  // cout << u << ' ' << val << '\n';
  return val;
}

void dfs2(int u, int val = 0, int fa = 0) {
  st[u].clear();
  st[u].insert(vis[u] ? 0 : n);
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    if (v == fa) f[u][i] = val+1;
    st[u].insert(f[u][i]);
  }
  g[u] = *st[u].begin();
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    if (v == fa) continue;
    st[u].erase(st[u].find(f[u][i]));
    dfs2(v, *st[u].begin(), u);
    st[u].insert(f[u][i]);
  }
}

inline bool solve() {
  cin >> n >> k;
  for (int i = 1, x; i <= k; ++i) {
    cin >> x;
    vis[x] = 1;
  }
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  dfs1(1);
  dfs2(1);
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) {
    orzeach(e[i]);
    orzeach(f[i]);
  }
  orzarr(d+1, n);
  orzarr(g+1, n);
  #endif
  for (int i = 2; i <= n; ++i) if (e[i].size() == 1u) {
    if (d[i] < g[i]) return true;
  }
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
    for (int i = 1; i <= n; ++i) {
      vis[i] = 0;
      e[i].clear();
    }
  }
  return 0;
}