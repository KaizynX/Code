/*
 * @Author: Kaizyn
 * @Date: 2020-07-26 14:04:58
 * @LastEditTime: 2020-07-26 14:06:20
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;

double p;

inline bool solve() {
  cin >> p;
  if (p > 1) return false;
  return p*2+p*0.5 > 2*p;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}