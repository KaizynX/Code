/*
 * @Author: Kaizyn
 * @Date: 2020-06-06 13:39:06
 * @LastEditTime: 2020-06-06 13:55:16
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e4+7;

int n, a, b;

inline string solve() {
  cin >> n >> a >> b;
  if (n == 1) return a ? "UP" : "DOWN";
  /*
  if (a%2 == 0 && b%2 == 0) return "ALL";
  if (a%2 == 0) return "DOWN";
  if (b%2 == 0) return "UP";
  */
  if (n%2 == 0) return "ALL";
  if (b%2 == 1) return "DOWN";
  if (a%2 == 1) return "UP";
  return "NULL";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << solve() << endl;
  }
  return 0;
}