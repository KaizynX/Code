/*
 * @Author: Kaizyn
 * @Date: 2021-02-04 18:13:19
 * @LastEditTime: 2021-02-04 18:19:53
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
const int M = 27*27*27*27;

int n, m, k;
int mt[N], vis[M], deg[N];
string p[N], s[N];
vector<int> e[N];

inline int myHash(const string &str, int bit = 0) {
  // [a, z]->[1, 26], [_]->[0]
  int h = 0;
  for (int i = 0; i < k; ++i) {
    if (((bit>>i)&1) || str[i] == '_') h = h*27;
    else h = h*27+str[i]-'a'+1;
  }
  return h;
}

inline bool cmp(const string &x, const string &y) {
  for (int i = 0; i < k; ++i) {
    if (x[i] == y[i] || x[i] == '_' || y[i] == '_') continue;
    return false;
  }
  return true;
}

inline void solve() {
  string str;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    vis[myHash(p[i])] = i;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> s[i] >> mt[i];
  }
  for (int i = 1; i <= m; ++i) {
    if (!cmp(s[i], p[mt[i]])) return cout << "NO\n", void();
    for (int b = 0; b < 1<<k; ++b) {
      int h = myHash(s[i], b);
      if (vis[h] && vis[h] != mt[i]) {
        e[mt[i]].emplace_back(vis[h]);
        ++deg[vis[h]];
      }
    }
  }
  queue<int> q;
  vector<int> res;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) q.push(i);
  }
  while (q.size()) {
    int u = q.front();
    q.pop();
    res.emplace_back(u);
    for (int &v : e[u]) {
      if (--deg[v] == 0) q.push(v);
    }
  }
  if ((int)res.size() < n) return cout << "NO\n", void();
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i==n-1];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}