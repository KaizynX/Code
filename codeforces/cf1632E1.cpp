/*
 * @Author: Kaizyn
 * @Date: 2022-01-30 23:33:37
 * @LastEditTime: 2022-01-31 00:08:21
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
const int N = 3e3 + 7;

struct HLD {
  int fa[N], d[N], num[N], son[N], tp[N], mx[N];
  vector<int> *e;
  void build(vector<int> *e, const int &rt = 1) {
    this->e = e;
    fa[rt] = 0;
    dfs1(rt);
    dfs2(rt);
  }
  int dfs1(const int &u = 1) {
    mx[u] = 0;
    d[u] = d[fa[u]]+1;
    num[u] = 1;
    son[u] = 0;
    for (const int &v : e[u]) if (v != fa[u]) {
      fa[v] = u;
      mx[u] = max(mx[u], dfs1(v) + 1);
      num[u] += num[v];
      if (num[v] > num[son[u]]) son[u] = v;
    }
    return mx[u];
  }
  void dfs2(const int &u = 1) {
    tp[u] = son[fa[u]] == u ? tp[fa[u]] : u;
    if (son[u]) dfs2(son[u]);
    for (const int &v : e[u]) if (v != son[u] && v != fa[u])
      dfs2(v);
  }
  int lca(int x, int y) {
    while (tp[x] != tp[y]) {
      if (d[tp[x]] < d[tp[y]]) swap(x, y);
      x = fa[tp[x]];
    }
    return d[x] < d[y] ? x : y;
  }
};

int n;
vector<int> e[N];
HLD tree;
int *d = tree.d;
int *mx = tree.mx;

inline int check(int mid) {
  int lca = -1;
  for (int i = 1; i <= n; ++i) if (d[i] - 1 > mid) {
    lca = ~lca ? tree.lca(lca, i) : i;
  }
  return ~lca ? mx[lca] : -INF;
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  tree.build(e);
  #ifdef DEBUG
  orzarr(mx + 1, n);
  #endif
  int mxd = *max_element(mx + 1, mx + n + 1);
  for (int i = 1; i <= n; ++i) {
    int l = mxd / 2, r = mxd, mid;
    while (l < r) {
      mid = (l + r) / 2;
      if (check(mid) + i <= mid) r = mid;
      else l = mid + 1;
    }
    cout << l << " \n"[i == n];
  }
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
      e[i].clear();
    }
  }
  return 0;
}