/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 16:17:57
 * @LastEditTime: 2020-07-17 17:20:07
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e5+7;

int n, k, m;
int d[N], deg[N], cir[N], res[N], del[N];
int buf[N*3], *cnt, sum;
vector<int> e[N];
queue<int> q;

void dfs(const int &u, const int &dep, const int &val) {
  if (dep > k) return;
  cnt[dep] += val;
  sum += val;
  for (const int &v : e[u]) {
    dfs(v, dep+1, val);
  }
}

#ifdef DEBUG
void print() {
  cout << sum << ": ";
  for (int i = 0; i <= k; ++i) {
    cout << cnt[i] << " \n"[i==k];
  }
}
#endif

int dfs2(const int &u, const int &dep) {
  res[u] = 1;
  for (const int &v : e[u]) {
    res[u] += dfs2(v, dep+1);
  }
  res[u] -= del[dep];
  del[dep] = 0;
  if (dep > k) ++del[dep-k-1];
  return res[u];
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    ++deg[d[i]];
  }
  for (int i = 1; i <= n; ++i) {
    if (!deg[i]) q.push(i);
  }
  while (q.size()) {
    int u = q.front(), v = d[u];
    q.pop();
    e[v].emplace_back(u);
    if (--deg[v] == 0) q.push(v);
  }
  for (int st = 1; st <= n; ++st) if (deg[st]) {
    m = 0;
    deg[st] = 0;
    cir[m++] = st;
    for (int i = d[st]; i != st; i = d[i]) {
      deg[i] = 0;
      cir[m++] = i;
    }
    for (int i = 0; i < m; ++i) {
      dfs2(cir[i], 0);
    }
    cnt = buf+2*N;
    sum = 0;
    for (int i = 0; i < m; ++i) {
      dfs(cir[i], 0, 1);
      #ifdef DEBUG
      print();
      #endif
      sum -= cnt[k];
      // cnt[k] = 0;
      --cnt;
      // cnt[0] = 0;
    }
    for (int i = 0; i < m; ++i) {
      dfs(cir[i], m, -1);
      dfs(cir[i], 0, 1);
      res[cir[i]] = sum;
      #ifdef DEBUG
      print();
      #endif
      sum -= cnt[k];
      // cnt[k] = 0;
      --cnt;
      // cnt[0] = 0;
    }
    // clear
    for (int i = m-1; i >= 0; --i) {
      ++cnt;
      dfs(cir[i], 0, -1);
      dfs(cir[i], m, 1);
    }
    for (int i = m-1; i >= 0; --i) {
      ++cnt;
      dfs(cir[i], 0, -1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << endl;
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