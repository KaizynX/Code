/*
 * @Author: Kaizyn
 * @Date: 2020-07-21 22:33:02
 * @LastEditTime: 2020-07-22 10:01:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e3+3;

int n;
int p[N];
bitset<2048> dp;

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= 2*n; ++i) cin >> p[i];
  dp.reset();
  dp.set(0);
  int len = 0;
  for (int i = 1, mx = 0; i <= n*2; ++i) {
    if (p[i] > mx) {
      dp |= dp<<len;
      mx = p[i];
      len = 1;
    } else {
      ++len;
    }
  }
  return dp[n];
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}