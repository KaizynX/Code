/*
 * @Author: Kaizyn
 * @Date: 2021-08-27 13:16:59
 * @LastEditTime: 2021-08-27 13:20:27
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
const int N = 1e5+7;

struct TireTree {
  static const int SZ = 2;
  static const int B = 30;
  static const int NN = N*B;
  int nex[NN][SZ], cnt;
  void init() { clear(); }
  void clear() {
    memset(nex, 0, sizeof(int)*(cnt+1)*SZ);
    cnt = 0;
  }
  void insert(int x) {
    for (int i = B, c, p = 0; i >= 0; --i) {
      c = (x>>i)&1;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
  }
  int max_xor(int x) const {
    int ans = 0;
    for (int i = B, c, p = 0; i >= 0; --i) {
      c = (x>>i)&1;
      if (!nex[p][c^1]) p = nex[p][c];
      else p = nex[p][c^1], ans |= 1<<i;
    }
    return ans;
  }
};

int n, ans;
int a[N];
vector<pii> e[N];

namespace DFZ {
int vis[N], siz[N], mxs[N];
vector<int> pset;
TireTree tree;

void calc_size(int u, int fa = 0) { // 找重心
  siz[u] = 1; mxs[u] = 0;
  pset.emplace_back(u);
  for (auto p : e[u]) {
    int v = p.first;
    if (v == fa || vis[v]) continue;
    calc_size(v, u);
    siz[u] += siz[v];
    mxs[u] = max(mxs[u], siz[v]);
  }
}

template <int mode>
void dfs(int u, int fa, int val) {
  if (mode) tree.insert(val);
  else ans = max(ans, tree.max_xor(val));
  for (auto p : e[u]) {
    int v = p.first;
    if (v == fa || vis[v]) continue;
    dfs<mode>(v, u, val^p.second);
  }
}

void dfz(int u = 1) {
  pset.clear();
  calc_size(u);
  for (int v : pset) { // get centre
    mxs[v] = max(mxs[v], (int)pset.size()-siz[v]);
    if (mxs[v] < mxs[u]) u = v;
  }
  tree.insert(0);
  for (auto p : e[u]) {
    int v = p.first;
    if (vis[v]) continue;
    dfs<0>(v, u, p.second);
    dfs<1>(v, u, p.second);
  }
  tree.clear();
  vis[u] = 1;
  for (auto p : e[u]) {
    int v = p.first;
    if (vis[v]) continue;
    dfz(v);
  }
}
} // namespace 点分治

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  DFZ::dfz();
  cout << ans << '\n';
  return 0;
}