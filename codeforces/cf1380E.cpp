/*
 * @Author: Kaizyn
 * @Date: 2020-07-14 13:09:11
 * @LastEditTime: 2020-07-14 13:45:22
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

struct DSU {
  int fa[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
};

int n, m;
int t[N];
DSU dsu;
set<pii> st[N];
vector<int> vec[N];

inline void solve() {
  cin >> n >> m;
  dsu.init(m);
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    vec[t[i]].emplace_back(i);
  }
  int res = 0;
  for (int i = 1; i <= m; ++i) {
    if (vec[i].empty()) continue;
    int l = vec[i].front(), r = vec[i].front();
    for (int j = 1; j < (int)vec[i].size(); ++j) {
      if (vec[i][j] == r+1) ++r;
      else {
        st[i].insert({l, r});
        l = r = vec[i][j];
      }
    }
    st[i].insert({l, r});
    res += st[i].size();
  }
  cout << res-1 << endl;
  for (int i = 1, x, y; i < m; ++i) {
    cin >> x >> y;
    // merge y to x
    if (st[x].size() < st[y].size()) swap(st[x], st[y]);
    for (const pii &pr : st[y]) {
      pii p = pr;
      auto it = st[x].upper_bound(p);
      if (st[x].size() && it != st[x].begin()) {
        --it;
        if (it->second == p.first-1) {
          p.first = it->first;
          st[x].erase(it);
          --res;
        }
      }
      it = st[x].upper_bound(p);
      if (it != st[x].end()) {
        if (it->first == p.second+1) {
          p.second = it->second;
          st[x].erase(it);
          --res;
        }
      }
      st[x].insert(p);
    }
    st[y].clear();
    cout << res-1 << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}