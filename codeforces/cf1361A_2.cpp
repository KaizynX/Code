/*
 * @Author: Kaizyn
 * @Date: 2020-06-04 22:31:32
 * @LastEditTime: 2020-06-04 23:16:32
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

int n, m;
vector<int> e[N], vec[N];
vector<int> res;
int t[N], c[N];
queue<int> q;

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> t[i];
    vec[t[i]].emplace_back(i);
    /*
    sort(e[i].begin(), e[i].end());
    for (int j = 0; j < (int)e[i].size(); ++j) {
      if (t[e[i][j]] != j+1) {
        c[i] = j+1;
        break;
      }
    }
    if (!c[i]) c[i] = e[i].size()+1;
    */
  }
  vector<int> tmp;
  for (int i = 1; i <= n; ++i) {
    for (const int &j : vec[i]) {
      tmp.clear();
      for (const int &k : e[j]) {
        if (c[k]) tmp.emplace_back(c[k]);
      }
      sort(tmp.begin(), tmp.end());
      tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
      for (int k = 0; k < (int)tmp.size(); ++k) {
        if (tmp[k] != k+1) {
          c[j] = k+1;
          break;
        }
      }
      if (!c[j]) c[j] = tmp.size()+1;
      if (c[j] != t[j]) return cout << -1 << endl, void();
      res.emplace_back(j);
    }
  }
  for (const int &i : res) cout << i << " ";
  cout << endl;
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