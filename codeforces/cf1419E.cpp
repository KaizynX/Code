/*
 * @Author: Kaizyn
 * @Date: 2020-09-19 22:31:13
 * @LastEditTime: 2020-09-19 23:56:04
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

int n, m, a;
int k[N], t[N];
long long p[N];

void f(const int &u) {
  if (u > m) {
    if (a > 1) cout << a << " ";
    return;
  }
  if (t[u] == k[u]) {
    for ( ; t[u]; --t[u]) {
      f(u+1);
      a /= p[u];
    }
    f(u+1);
  } else {
    for ( ; t[u] < k[u]; ++t[u]) {
      f(u+1);
      a *= p[u];
    }
    f(u+1);
  }
}

inline void solve() {
  cin >> n;
  m = 0;
  a = 1;
  for (int i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    p[++m] = i;
    k[m] = t[m] = 0;
    while (n%i == 0) n /= i, ++k[m];
  }
  if (n > 1) {
    p[++m] = n;
    k[m] = 1;
    t[m] = 0;
  }
  f(1);
  cout << endl << 0 << endl;
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