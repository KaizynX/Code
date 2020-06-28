/*
 * @Author: Kaizyn
 * @Date: 2020-06-24 18:12:39
 * @LastEditTime: 2020-06-24 21:07:31
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

int k, n;
int f[N], c[N];
vector<int> e[N];

void build(const int &fa, const int &kk) {
  int u = fa;
  if (kk&1) {
    ++n;
    f[n] = fa;
    u = n;
    // e[fa].emplace_back(u);
  }
  if (kk <= 1) return;
  ++n;
  f[n] = u;
  // e[u].emplace_back(n);
  ++n;
  f[n] = n-1;
  // e[n-1].emplace_back(n);
  build(u, kk/2);
}

void get_val(const int &u) {
  if (!e[u].size()) return c[u] = 1, void();
  c[u] = 0;
  for (const int &v : e[u]) {
    get_val(v);
    c[u] += c[v];
  }
}

inline void solve() {
  cin >> k;
  n = 1;
  build(1, k);
  cout << n << endl;
  for (int i = 2; i <= n; ++i) {
    cout << f[i] << " \n"[i==n];
    e[f[i]].emplace_back(i);
  }
  get_val(1);
  c[1] = 1000000000;
  for (int i = 1; i <= n; ++i) cout << c[i] << " \n"[i==n];
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