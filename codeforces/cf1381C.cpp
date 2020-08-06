/*
 * @Author: Kaizyn
 * @Date: 2020-07-22 00:18:51
 * @LastEditTime: 2020-07-22 00:35:07
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

int n, x, y;
int a[N], b[N], rk[N];
vector<int> p[N], vy;

inline void solve() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    p[b[i]].emplace_back(i);
  }

  y -= x;
  for (int i = 1; i <= n+1; ++i) {
    rk[i] = i;
    if (p[i].empty()) a[0] = i;
  }
  for (int i = 1; i <= n; ++i) a[i] = a[0];
  sort(rk+1, rk+n+2, [](int x, int y) { return p[x].size() < p[y].size(); });
  if (y == 1) {
    vy.emplace_back(1);
  } else {
  vy.clear();
  for (int i = 1, j = 0; (int)vy.size() < y && i <= n+1; ++i) {
    j = 0;
    while ((int)vy.size() < y && p[rk[i]].size() && j+1 <= y/2) {
      vy.emplace_back(p[rk[i]].back());
      p[rk[i]].pop_back();
      ++j;
    }
  }
  for (int i = 0; i < y; ++i) {
    a[vy[i]] = b[vy[(i+y/2)%y]];
  }
  }
  for (int i = 1; x && i <= n+1; ++i) {
    while (x && p[i].size()) {
      a[p[i].back()] = i;
      p[i].pop_back();
      --x;
    }
  }
  if (x || (int)vy.size() < y) return cout << "NO" << endl, void();
  cout << "YES" << endl;
  for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  cout.flush();
  for (int i = 1; i <= n+1; ++i) {
    vector<int>().swap(p[i]);
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