/*
 * @Author: Kaizyn
 * @Date: 2021-10-01 15:10:04
 * @LastEditTime: 2021-10-01 19:01:51
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
const int N = 4e5+7;
const int LOG = log(N)+2;

char s[N];
int n, m, na, nb, sz;
int a[N], b[N], dep[N], lena[N], fa[N][LOG], endp[N], deg[N];
ll dis[N];
vector<pii> e[N];

struct SAM { // root 0
  static const int A = 26;
  static const char C = 'a';
  int sz, last, len[N], link[N], nex[N][A];
  void init() {
    for (int i = 0; i <= sz; ++i) {
      memset(nex[i], 0, sizeof nex[i]);
      memset(fa[i], 0, sizeof fa[i]);
      dis[i] = deg[i] = 0;
      e[i].clear();
    }
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
} sam;

void dfs(int u = 0) {
  for (int i = 1; (1<<i) <= dep[u]; ++i)
    fa[u][i] = fa[fa[u][i-1]][i-1];
  for (auto edge : e[u]) {
    int v = edge.first;
    dep[v] = dep[u]+1;
    fa[v][0] = u;
    dfs(v);
  }
}

int get_pos(int l, int r) {
  int p = endp[r];
  for (int i = log(dep[p]); i >= 0; --i)
    if (sam.len[fa[p][i]] >= r-l+1) p = fa[p][i];
  return p;
}

ll bfs() {
  queue<int> q;
  int cnt = 0;
  for (int i = 0; i <= sz; ++i) if (!deg[i]) q.push(i);
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
  return cnt == sz+1 ? dis[sz] : -1;
}

inline void solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  reverse(s+1, s+n+1);
  sam.init();
  for (int i = 1; i <= n; ++i) {
    endp[i] = sam.last = sam.extend(s[i]-'a');
  }
  scanf("%d", &na);
  sz = sam.sz;
  for (int i = 1; i < sz; ++i) {
    e[sam.link[i]].emplace_back(i, 0); ++deg[i];
  }
  dfs();
  for (int i = 1, l, r; i <= na; ++i) {
    scanf("%d%d", &l, &r);
    lena[i] = r-l+1;
    a[i] = get_pos(n-r+1, n-l+1);
    e[a[i]].emplace_back(sz, lena[i]); ++deg[sz];
  }
  scanf("%d", &nb);
  for (int i = 1, l, r; i <= nb; ++i) {
    scanf("%d%d", &l, &r);
    b[i] = get_pos(n-r+1, n-l+1);
  }
  scanf("%d", &m);
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    e[a[x]].emplace_back(b[y], lena[x]); ++deg[b[y]];
  }
  #ifdef DEBUG
  for (int i = 1; i <= na; ++i) {
    cout << i << ' ' << a[i] << '\n';
  }
  for (int i = 1; i <= nb; ++i) {
    cout << i << ' ' << b[i] << '\n';
  }
  for (int i = 0; i <= sz; ++i) {
    cout << i << ' ';
    orzeach(e[i]);
  }
  #endif
  printf("%lld\n", bfs());
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