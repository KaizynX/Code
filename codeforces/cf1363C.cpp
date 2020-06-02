/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 22:29:52
 * @LastEditTime: 2020-05-31 22:54:21
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e3+7;

int n, x;
vector<int> e[N];

inline void solve() {
  cin >> n >> x;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  /*
  n -= 1+e[x].size();
  cout << (n&1 ? "Ayush" : "Ashish") << endl;
  */
  if (e[x].size() <= 1 || (n-1)&1) cout << "Ayush" << endl;
  else cout << "Ashish" << endl;
  for (int i = 1; i <= n; ++i) {
    vector<int>().swap(e[i]);
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