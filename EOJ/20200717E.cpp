/*
 * @Author: Kaizyn
 * @Date: 2020-07-17 20:08:21
 * @LastEditTime: 2020-07-17 20:16:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 15;

int n;
int k[N], t[N];
long long a = 1;
long long p[N];

void f(const int &u) {
  if (u > n) return cout << a << endl, void();
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
  for (int i = 1; i <= n; ++i) {
  // for (int i = n; i; --i) {
    cin >> p[i] >> k[i];
  }
  p[0] = 1;
  // f(0);
  f(1);
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