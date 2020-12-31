/*
 * @Author: Kaizyn
 * @Date: 2020-12-17 23:21:27
 * @LastEditTime: 2020-12-18 00:24:32
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

int n, k;
int p[N], u[N], v[N];
int deg[N], ind[N], otd[N], spj[N], nex[N], pre[N];
int fa[N], num[N], cnt[N], ok[N];
vector<int> e[N], res;
deque<int> q;

void dsu_init() { 
  for (int i = 0; i <= n; ++i) {
    fa[i] = i;
    num[i] = 1;
  }
}

int getf(int s) { return s == fa[s] ? s : fa[s] = getf(fa[s]); }

bool merge(int x, int y) {
  int fx = getf(x), fy = getf(y);
  if (fx == fy) return false;
  fa[fy] = fx;
  num[fx] += num[fy];
  return true;
}

void add(int h) {
  static vector<int> vec;
  // vec.clear();
  for (int i = h; i; i = nex[i]) vec.push_back(i), res.push_back(i);
  while (vec.size()) q.push_front(vec.back()), vec.pop_back();
}

bool check() {
  for (int i = 1; i <= n; ++i) {
    e[p[i]].emplace_back(i);
    ++deg[i];
  }
  for (int i = 1; i <= k; ++i) {
    e[u[i]].emplace_back(v[i]);
    ++deg[v[i]];
  }
  q.push_back(0);
  int cnt = 0;
  while (q.size()) {
    int u = q.front();
    q.pop_front();
    ++cnt;
    for (int &v : e[u]) {
      if (--deg[v] == 0) q.push_back(v);
    }
  }
  q.clear();
  for (int i = 1; i <= n; ++i) {
    e[i].clear();
    deg[i] = 0;
  }
  return cnt == n+1;
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) cin >> p[i];
  for (int i = 1; i <= k; ++i) cin >> u[i] >> v[i];
  if (!check()) return cout << 0 << endl, void();

  for (int i = 1; i <= n; ++i) {
    e[p[i]].emplace_back(i);
    ++deg[i];
  }
  dsu_init();
  int flag = 1;
  for (int i = 1; i <= k; ++i) {
    pre[v[i]] = u[i];
    nex[u[i]] = v[i];
    spj[u[i]] = spj[v[i]] = 1;
    if (++ind[v[i]] > 1 || ++otd[u[i]] > 1) flag = 0;
    if (!merge(u[i], v[i])) flag = 0;
  }
  if (!flag) return cout << 0 << endl, void();

  for (int i = 1; i <= n; ++i) {
    if (!spj[i]) cnt[i] = -1;
    else cnt[i] = getf(p[i]) == getf(i);
    ok[getf(i)] += deg[i] == cnt[i];
#ifdef DEBUG
    cout << cnt[i] << " \n"[i==n];
#endif
  }
  q.push_back(0);
  while (q.size()) {
    int u = q.front();
    q.pop_front();
    if (!spj[u]) res.emplace_back(u);
    for (int &v : e[u]) {
      int fv = getf(v);
      --deg[v];
      if (!spj[v]) {
        if (!deg[v]) q.push_back(v);
      } else {
        ok[fv] += deg[v] == cnt[v];
        if (ok[fv] == num[fv]) {
          ok[fv] = -INF;
          add(fv);
        }
      }
    }
  }
  if ((int)res.size() < n+1) cout << 0 << endl;
  else for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
}

signed main() {
#ifndef DEBUG
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}