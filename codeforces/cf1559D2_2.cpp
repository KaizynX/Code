/*
 * @Author: Kaizyn
 * @Date: 2021-08-16 00:12:35
 * @LastEditTime: 2021-08-16 00:18:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

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

int n, m[2], rk[N];
DSU dsu[2];
vector<int> pt[N];
vector<pii> res;
map<int, list<int>> mp;

void fuck() {
  mp.clear();
  swap(dsu[0], dsu[1]);
  for (int i = 1; i <= n; ++i) {
    pt[dsu[0][i]].emplace_back(i);
    swap(rk[i], rk[rnd()%i+1]);
  }
  for (int _ = 1, i; _ <= n; ++_) {
    i = rk[_];
    if (pt[i].empty()) continue;
    for (int j : pt[i]) {
      auto it = mp.begin();
      while (it != mp.end() && it->first == dsu[1][j]) ++it;
      if (it != mp.end()) {
        int k = it->second.back();
        dsu[1].merge(k, j); // merge k to j
        res.emplace_back(j, k);
        mp[dsu[1][j]].splice(mp[dsu[1][j]].end(), it->second);
        // mp[it->first].splice(mp[it->first].end(), it->second);
        mp.erase(it);
        dsu[0].merge(dsu[0][k], dsu[0][j]);
        break;
      }
    }
    for (int j : pt[i]) mp[dsu[1][j]].push_back(j);
  }
  for (int i = 1; i <= n; ++i) pt[i].clear();
}

inline void solve() {
  cin >> n >> m[0] >> m[1];
  res.clear();
  for (int i : {0, 1}) {
    dsu[i].init(n);
    for (int j = 1, u, v; j <= m[i]; ++j) {
      cin >> u >> v;
      dsu[i].merge(u, v);
    }
  }
  iota(rk+1, rk+n+1, 1);
  for (int i = 0; i < 10; ++i) fuck();
  cout << res.size() << '\n';
  for (auto i : res) cout << i.first << ' ' << i.second << '\n';
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