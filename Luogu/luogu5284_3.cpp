/*
 * @Author: Kaizyn
 * @Date: 2021-10-01 15:10:04
 * @LastEditTime: 2021-10-01 19:30:14
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
int n, m, na, nb, id;
int a[N], b[N], lena[N], lenb[N], deg[M+N+N];
ll dis[M+N+N];
vector<pii> e[M+N+N];
map<int, int> mp[M];

struct SAM { // root 0
  static const int A = 26;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A];
  int t[M], rk[M], fa[LOG][M], pos[N], dep[M];
  void init() {
    for (int i = 0; i <= sz; ++i) {
      mp[i].clear();
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
    dep[0] = 0;
    for (int _ = 1, i, j; _ < sz; ++_) {
      i = rk[_];
      j = link[i];
      fa[0][i] = j;
      dep[i] = dep[j]+1;
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
    mp[a[i]][lena[i]] = 0;
  }
  scanf("%d", &nb);
  for (int i = 1, l, r; i <= nb; ++i) {
    scanf("%d%d", &l, &r);
    lenb[i] = r-l+1;
    b[i] = sam.get_pos(n-r+1, n-l+1);
    mp[b[i]][lenb[i]] = 0;
  }
  // 拆点
  int ids = 0;
  for (int i = 0; i <= T; ++i) {
    if (mp[i].empty()) mp[i][sam.len[i]] = 0;
    for (auto it = mp[i].begin(); it != mp[i].end(); ++it) {
      it->second = ++ids;
      if (it != mp[i].begin()) {
        e[ids-1].emplace_back(ids, 0); ++deg[ids];
      }
    }
  }
  for (int i = 1, ii, jj, j; i < T; ++i) {
    j = sam.link[i];
    ii = mp[i].begin()->second;
    jj = mp[j].rbegin()->second;
    e[jj].emplace_back(ii, 0); ++deg[ii];
  }
  T = mp[T].begin()->second;
  for (int i = 1; i <= na; ++i) {
    a[i] = mp[a[i]][lena[i]];
    e[a[i]].emplace_back(T, lena[i]); ++deg[T];
  }
  for (int i = 1; i <= nb; ++i) {
    b[i] = mp[b[i]][lenb[i]];
  }
  // 拆点
  scanf("%d", &m);
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    e[a[x]].emplace_back(b[y], lena[x]); ++deg[b[y]];
  }
#ifdef DEBUG
  for (int i = 0; i <= sam.sz; ++i) {
    printf("e[%d].size(%d),%d\n", i, (int)mp[i].size(), mp[i].begin()->second);
  }
  for (int i = 1; i <= ids; ++i) {
    cout << i << ' '; orzeach(e[i]);
  }
#endif
  int cnt = 0;
  queue<int> q;
  for (int i = 1; i <= ids; ++i) if (!deg[i]) q.push(i);
  while (q.size()) {
    int u = q.front();
    q.pop();
    #ifdef DEBUG
    orz(u);
    #endif
    ++cnt;
    for (auto edge : e[u]) {
      int v = edge.first;
      int w = edge.second;
      dis[v] = max(dis[v], dis[u]+w);
      if (--deg[v] == 0) q.push(v);
    }
  }
  #ifdef DEBUG
  orz(cnt);
  orz(ids);
  #endif
  printf("%lld\n", cnt == ids ? dis[T] : -1ll);
  for (int i = 1; i <= ids; ++i) {
    dis[i] = deg[i] = 0;
    e[i].clear();
  }
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