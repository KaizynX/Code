/*
 * @Author: Kaizyn
 * @Date: 2020-06-23 22:01:27
 * @LastEditTime: 2020-06-23 22:09:25
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

int n;

inline void solve() {
  cin >> n;
  cout << (n%4 ? "NO" : "YES") << endl;
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