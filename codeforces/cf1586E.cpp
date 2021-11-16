/*
 * @Author: Kaizyn
 * @Date: 2021-11-15 18:30:42
 * @LastEditTime: 2021-11-15 19:59:34
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
const int N = 3e5+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m, q;
int fa[N], dep[N], a[N], b[N], visp[N], visq[N];
DSU dsu;
vector<int> e[N], qe[N], ans[N], stk, cur;

vector<int> get_path(int x, int y) {
  vector<int> path, tmp;
  while (x != y) {
    if (dep[x] >= dep[y]) {
      path.emplace_back(x);
      x = fa[x];
    } else {
      tmp.emplace_back(y);
      y = fa[y];
    }
  }
  path.emplace_back(x);
  path.insert(path.end(), tmp.rbegin(), tmp.rend());
  return path;
}

void combine(vector<int> &cur, vector<int> &path) {
  for (int i : path) {
    if (cur.size() && cur.back() == i) {
      continue;
    } else if (cur.size() > 2u && cur.rbegin()[1] == i) {
      cur.pop_back();
    } else {
      cur.emplace_back(i);
    }
  }
}

void dfs(int u) {
  for (int v : e[u]) if (v != fa[u]) {
    dep[v] = dep[u]+1;
    fa[v] = u;
    dfs(v);
  }
}

void work(int u) {
  visp[u] ^= 1;
  for (int i : qe[u]) {
    if (visq[i]) continue;
    visq[i] = 1;
    int v = a[i] == u ? b[i] : a[i];
    if (visp[v]) {
      visp[u] = 0;
      for (int j, k = u; ; stk.pop_back()) {
        j = stk.back();
        k = a[j] == k ? b[j] : a[j];
        visp[k] ^= 1;
        if (k == v) break;
      }
      while (cur.back() != v) {
        ans[i].emplace_back(cur.back());
        cur.pop_back();
      }
      ans[i].emplace_back(v);
      cur.pop_back();
    } else {
      ans[i] = get_path(u, v);
      combine(cur, ans[i]);
    }
    stk.push_back(i);
    work(v);
  }
}

inline void solve() {
  cin >> n >> m;
  dsu.init(n);
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    if (dsu.merge(u, v)) {
      e[u].emplace_back(v);
      e[v].emplace_back(u);
    }
  }
  dfs(1);
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    cin >> a[i] >> b[i];
    qe[a[i]].emplace_back(i);
    qe[b[i]].emplace_back(i);
  }
  int spj = 0;
  for (int i = 1; i <= n; ++i) spj += qe[i].size()&1;
  if (spj) return cout << "NO\n" << spj/2 << '\n', void();
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) work(i);
  for (int i = 1; i <= q; ++i) {
    cout << ans[i].size() << '\n';
    if (ans[i].front() != a[i]) reverse(ans[i].begin(), ans[i].end());
    for (int j : ans[i]) cout << j << ' ';
    cout << '\n';
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