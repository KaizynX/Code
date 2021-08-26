/*
 * @Author: Kaizyn
 * @Date: 2021-08-26 15:36:25
 * @LastEditTime: 2021-08-26 16:48:46
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
const int N = 1e4+7;
const int M = 1e2+7;
const int K = 1e7+7;

int n, m, k;
int q[M], ans[M];
vector<pii> e[N];

namespace DFZ {
int vis[N], siz[N], mxs[N], cnt[K];
vector<int> pset;

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

void query(int u, int fa, int dis) {
  for (int i = 1; i <= m; ++i) if (q[i] >= dis) ans[i] |= cnt[q[i]-dis];
  for (auto p : e[u]) {
    int v = p.first;
    if (v == fa || vis[v]) continue;
    query(v, u, dis+p.second);
  }
}

void update(int u, int fa, int dis, int k) {
  if (dis < K) cnt[dis] += k;
  for (auto p : e[u]) {
    int v = p.first;
    if (v == fa || vis[v]) continue;
    update(v, u, dis+p.second, k);
  }
}

void dfz(int u = 1) {
  pset.clear();
  calc_size(u);
  for (int v : pset) { // get centre
    mxs[v] = max(mxs[v], (int)pset.size()-siz[v]);
    if (mxs[v] < mxs[u]) u = v;
  }
  cnt[0] = 1;
  for (auto p : e[u]) {
    int v = p.first;
    if (vis[v]) continue;
    query(v, u, p.second);
    update(v, u, p.second, 1);
  }
  update(u, 0, 0, -1); // clear
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
  scanf("%d%d", &n, &m);
  for (int i = 1, u, v, w; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  for (int i = 1; i <= m; ++i) scanf("%d", q+i);
  DFZ::dfz(1);
  for (int i = 1; i <= m; ++i) puts(ans[i] ? "AYE" : "NAY");
  return 0;
}