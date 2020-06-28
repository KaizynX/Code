/*
 * @Author: Kaizyn
 * @Date: 2020-06-23 20:41:53
 * @LastEditTime: 2020-06-23 20:51:05
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
int fa[N];

void add(const int &x) {
  for (int i = 1, u = 1; i <= x; ++i) {
    fa[++n] = u;
    u = n;
  }
}

inline void solve() {
  cin >> k;
  if (k == 1) return cout << "2\n1\n1 2\n", void();
  n = 1;
  for (int i = 2; i*i <= k; ++i) {
    while (k%i == 0) k /= i, add(i);
  }
  if (k > 1) add(k);
  cout << n << endl;
  for (int i = 2; i <= n; ++i) cout << fa[i] << " \n"[i==n];
  cout << 1000000000 << " ";
  for (int i = 2; i <= n; ++i) cout << 1 << " \n"[i==n];
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