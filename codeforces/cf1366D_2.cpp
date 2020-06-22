/*
 * @Author: Kaizyn
 * @Date: 2020-06-11 22:32:07
 * @LastEditTime: 2020-06-12 09:24:59
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
const int M = 1e7+7;

struct Euler {
  int tot = 0;
  int prime[M];
  int check[M];
  int& operator [] (const int i) { return check[i]; }
  void init(int sz) {
    tot = 0;
    check[1] = 0;
    for (register int i = 2, j; i <= sz; ++i) {
      if (!check[i]) prime[++tot] = i, check[i] = i;
      for (j = 1; j <= tot && i*prime[j] <= sz; ++j) {
        check[i*prime[j]] = prime[j];
        if (i%prime[j] == 0) break;
      }
    }
  }
} E;

int n;
int a[N];
int d[2][N];

inline void solve() {
  cin >> n;
  for (int i = 1, x, y, f; i <= n; ++i) {
    cin >> a[i];
    x = a[i]; y = 1;
    // f = get_fac(x); // 找最小一个
    f = E[x];
    while (x%f == 0) x /= f, y *= f;
    if (x == 1 || y == 1) d[0][i] = d[1][i] = -1;
    else d[0][i] = x, d[1][i] = y;
  }
  for (int i = 1; i <= n; ++i) cout << d[0][i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << d[1][i] << " \n"[i==n];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  E.init(10000000);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}