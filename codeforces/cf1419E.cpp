/*
 * @Author: Kaizyn
 * @Date: 2020-09-19 22:31:13
 * @LastEditTime: 2020-09-26 11:42:49
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
int k[N], p[N];

void get_prime(int n) {
  m = 0;
  for (int i = 2; i*i <= n; ++i) {
    if (n%i) continue;
    p[++m] = i;
    k[m] = 0;
    while (n%i == 0) n /= i, ++k[m];
  }
  if (n > 1) {
    p[++m] = n;
    k[m] = 1;
  }
}

inline void solve() {
  cin >> n;
  get_prime(n);
  if (m == 2) {
    if (k[1] == 1 && k[2] == 1) {
      cout << p[1] << " " << p[2] << " " << n << endl
          << 1 << endl;
    } else {
      cout << p[1] << " " << p[1]*p[2] << " " << n;
      for (int i = 0, pw1 = 1; i <= k[1]; ++i, pw1 *= p[1]) {
        for (int j = 0, pw2 = 1; j <= k[2]; ++j, pw2 *= p[2]) {
          if (i == 0 && j == 0) continue;
          if (i == 1 && j == 0) continue;
          if (i == 1 && j == 1) continue;
          if (i == k[1] && j == k[2]) continue;
          cout << pw1*pw2 << " ";
        }
      }
      cout << endl << 0 << endl;
    }
    return;
  }
  // too lazy to code
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