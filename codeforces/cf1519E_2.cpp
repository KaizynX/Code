/*
 * @Author: Kaizyn
 * @Date: 2021-04-29 23:56:54
 * @LastEditTime: 2021-04-30 14:46:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e5+7;
typedef tuple<int, int, int, int> Node;
typedef pair<ll, ll> pll;

int n;
int use[N], vis[N<<1];
Node p[N];
vector<pll> dis;
vector<pii> e[N<<1], res;

inline pll magic(ll a, ll b, ll c, ll d) {
  a *= d;
  b *= c;
  ll g = __gcd(a, b);
  return pll{a/g, b/g};
}

inline int lb(pll v) {
  return lower_bound(dis.begin(), dis.end(), v)-dis.begin()+1;
}

void dfs(int u, int f = -1, int fid = -1) {
  // static vector<int> vec;
  vis[u] = 1;
  for (auto &p : e[u]) {
    int v = p.first;
    int id = p.second;
    if (v == f || vis[v]) continue;
    dfs(v, u, id);
  }
  int last = -1;
  for (auto &p : e[u]) {
    int v = p.first;
    int id = p.second;
    if (v == f || use[id]) continue;
    if (~last) {
      res.emplace_back(last, id);
      use[last] = use[id] = 1;
      last = -1;
    } else {
      last = id;
    }
  }
  if (~last && ~fid) {
    res.emplace_back(last, fid);
    use[last] = use[fid] = 1;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, a, b, c, d; i <= n; ++i) {
    cin >> a >> b >> c >> d;
    p[i] = Node{a, b, c, d};
    dis.emplace_back(magic(a+b, b, c, d));
    dis.emplace_back(magic(a, b, c+d, d));
  }
  sort(dis.begin(), dis.end());
  dis.erase(unique(dis.begin(), dis.end()), dis.end());
  for (int i = 1, a, b, c, d, u, v; i <= n; ++i) {
    tie(a, b, c, d) = p[i];
    u = lb(magic(a+b, b, c, d));
    v = lb(magic(a, b, c+d, d));
    e[u].emplace_back(v, i);
    e[v].emplace_back(u, i);
  }
  for (int i = 1; i <= (int)dis.size(); ++i) {
    if (!vis[i]) dfs(i);
  }
  cout << res.size() << '\n';
  for (auto &p : res) cout << p.first << ' ' << p.second << '\n';
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