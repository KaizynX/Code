/*
 * @Author: Kaizyn
 * @Date: 2021-11-16 11:17:13
 * @LastEditTime: 2021-11-16 11:18:24
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
int fa[N], dep[N], a[N], b[N];
DSU dsu;
vector<int> e[N], qe[N];

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

void print(vector<int> v) {
  cout << v.size() << '\n';
  for (int i : v) cout << i << ' ';
  cout << '\n';
}

void dfs(int u) {
  for (int v : e[u]) if (v != fa[u]) {
    dep[v] = dep[u]+1;
    fa[v] = u;
    dfs(v);
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
  for (int i = 1; i <= q; ++i) {
    print(get_path(a[i], b[i]));
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
/*
7 6
1 2
1 4
2 3
2 5
3 6
3 7
6
3 5
5 4
4 3
3 6
6 7
7 3
*/