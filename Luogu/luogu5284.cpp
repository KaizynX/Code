/*
 * @Author: Kaizyn
 * @Date: 2021-10-01 15:10:04
 * @LastEditTime: 2021-10-01 19:01:35
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
#define log(x) (31-__builtin_clz(x))
const int N = 2e5+7;
const int M = N<<1;
const int LOG = log(M)+3;

char s[N];
int n, m, na, nb;
int a[N], b[N], lena[N], deg[M];
ll dis[M];
vector<pii> e[M];

struct SAM { // root 0
  static const int A = 26;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A];
  int t[M], rk[M], fa[LOG][M], pos[N], dep[M];
  void init() {
    for (int i = 0; i <= sz; ++i) {
      dis[i] = deg[i] = 0;
      e[i].clear();
      if (dep[i]) for (int j = 0; j <= log(dep[i]); ++j) fa[j][i] = 0;
    }
    memset(nex, 0, sizeof(int)*A*sz);
    link[0] = -1; sz = 1; last = 0;
  }
  int extend(int c) {
    int cur = sz++, p = last;
    len[cur] = len[last]+1;
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    link[clone] = link[q];
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[q] = link[cur] = clone;
    return cur;
  }
  void insert() {
    for (int i = 0; i < n; ++i) {
      last = extend(s[i]-C);
      pos[i+1] = last;
    }
  }
  void build() { // topo on parent tree
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    // for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
    dep[0] = 0;
    for (int _ = 1, i, j; _ < sz; ++_) {
      i = rk[_];
      j = link[i];
      fa[0][i] = j;
      dep[i] = dep[j]+1;
      e[j].emplace_back(i, 0); ++deg[i];
      for (int k = 1; 1<<k <= dep[i]; ++k) {
        fa[k][i] = fa[k-1][fa[k-1][i]];
      }
    }
  }
  int get_pos(int l, int r) {
    int p = pos[r];
    for (int i = log(dep[p]); i >= 0; --i) {
      if (len[fa[i][p]] >= r-l+1) p = fa[i][p];
    }
    return p;
  }
} sam;

inline void solve() {
  scanf("%s", s);
  n = strlen(s);
  reverse(s, s+n);
  sam.init();
  sam.insert();
  sam.build();
  scanf("%d", &na);
  int T = sam.sz;
  for (int i = 1, l, r; i <= na; ++i) {
    scanf("%d%d", &l, &r);
    lena[i] = r-l+1;
    a[i] = sam.get_pos(n-r+1, n-l+1);
    e[a[i]].emplace_back(T, lena[i]); ++deg[T];
  }
  scanf("%d", &nb);
  for (int i = 1, l, r; i <= nb; ++i) {
    scanf("%d%d", &l, &r);
    b[i] = sam.get_pos(n-r+1, n-l+1);
  }
  scanf("%d", &m);
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    e[a[x]].emplace_back(b[y], lena[x]); ++deg[b[y]];
  }
  int cnt = 0;
  queue<int> q;
  for (int i = 0; i <= T; ++i) if (!deg[i]) q.push(i);
  while (q.size()) {
    int u = q.front();
    q.pop();
    ++cnt;
    for (auto edge : e[u]) {
      int v = edge.first;
      int w = edge.second;
      dis[v] = max(dis[v], dis[u]+w);
      if (--deg[v] == 0) q.push(v);
    }
  }
  printf("%lld\n", cnt < sam.sz+1 ? -1ll : dis[T]);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}