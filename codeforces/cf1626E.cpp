/*
 * @Author: Kaizyn
 * @Date: 2022-01-16 23:00:26
 * @LastEditTime: 2022-01-16 23:36:53
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq []{cerr<<"qwq"<<endl;}()
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
const int N = 3e5+7;

int n, dfn;
int c[N], L[N], R[N], ans[N];
vector<int> e[N], d[N];
multiset<int> st[N];

void add(int l, int r, int val) {
  if (l > r) return;
  ans[l] += val;
  ans[r + 1] -= val;
}

void add(int i, int tag = 0) {
  if (tag) {
    add(1, n, 1);
    add(L[i], R[i], -1);
  } else {
    add(L[i], R[i], 1);
  }
}

int dfs1(int u = 1, int fa = 0) {
  L[u] = ++dfn;
  int dis = c[u] ? 0 : INF;
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    if (v == fa) continue;
    d[u][i] = dfs1(v, u);
    dis = min(dis, d[u][i]);
  }
  R[u] = dfn;
  return dis + 1;
}

void dfs2(int u = 1, int fa = 0, int dfa = INF) {
  st[u].clear();
  st[u].insert(INF);
  st[u].insert(c[u] ? 0 : INF);
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    if (v == fa) d[u][i] = dfa;
    st[u].insert(d[u][i]);
  }
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    st[u].erase(st[u].find(d[u][i]));
    auto fir = st[u].begin(), sec = ++st[u].begin();
    #ifdef DEBUG
    printf("u=%d,v=%d,fir=%d,sec=%d\n", u, v, *fir, *sec);
    #endif
    if (*fir <= 1 && *sec < INF) {
      if (v == fa) add(u, 1);
      else add(v);
    }
    if (v != fa) dfs2(v, u, *fir + 1);
    st[u].insert(d[u][i]);
  }
  st[u].clear();
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    d[i].resize(e[i].size(), INF);
  }
  dfs1();
  dfs2();
  for (int i = 1; i <= n; ++i) {
    if (c[i]) {
      add(L[i], L[i], 1);
      for (int j : e[i]) add(L[j], L[j], 1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    ans[i] += ans[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    cout << (ans[L[i]] == 0 ? 0 : 1) << " \n"[i == n];
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