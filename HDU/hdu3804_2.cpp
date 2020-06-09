/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 13:58:29
 * @LastEditTime: 2020-06-04 14:10:50
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m;
int res[N];
vector<pii> e[N], q[N];
multiset<int> st;

void dfs(const int &u, const int &fa) {
  for (const pii &p : q[u]) {
    auto it = st.upper_bound(p.second);
    if (it == st.begin()) res[p.first] = -1;
    else res[p.first] = *(--it);
  }
  for (const pii &p : e[u]) {
    int v = p.first, w = p.second;
    if (v == fa) continue;
    st.insert(w);
    dfs(v, u);
    st.erase(st.find(w));
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v, w; i < n; ++i) {
    cin >> u >> v >> w;
    e[u].emplace_back(v, w);
    e[v].emplace_back(u, w);
  }
  cin >> m;
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    q[x].emplace_back(i, y);
  }
  dfs(1, 0);
  for (int i = 1; i <= m; ++i) {
    cout << res[i] << endl;
  }
  for (int i = 1; i <= n; ++i) {
    vector<pii>().swap(e[i]);
    vector<pii>().swap(q[i]);
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}