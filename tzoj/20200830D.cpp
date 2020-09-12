/*
 * @Author: Kaizyn
 * @Date: 2020-08-30 13:11:13
 * @LastEditTime: 2020-08-30 13:12:49
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

struct Euler {
  int phi[N], check[N];
  vector<int> prime;
  void init(int sz) {
    for (int i = 1; i <= sz; ++i) check[i] = 1;
    phi[1] = 1; check[1] = 0;
    for (int i = 2; i <= sz; ++i) {
      if (check[i]) {
        prime.emplace_back(i);
        phi[i] = i-1;
      }
      for (int j : prime) {
        if (i*j > sz) break;
        check[i*j] = 0;
        if (i%j) {
          phi[i*j] = (j-1)*phi[i];
        } else {
          phi[i*j] = j*phi[i];
          break;
        }
      }
    }
  }
} E;

inline void solve() {
  int n;
  cin >> n;
  int x = 2;
  for (int i = 2; i <= n; ++i) {
    if (i-E.phi[i] <= x-E.phi[x]) x = i;
  }
  cout << x << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  E.init(1000000);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}