/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 13:16:18
 * @LastEditTime: 2020-06-13 13:25:14
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-2;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 30;

int n;
int a[N], p[N];

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += p[i]*a[i];
  }
  /*
  double sum = 0.0;
  for (int i = 1; i <= n; ++i) {
    sum += p[i]*a[i]/100.0;
  }
  return abs(4.0-0.04*sum) < eps;
  */
  // 4.0-0.04*sum/100 < 0.01
  // sum > 39900/4
  return sum > 9975;
  // return sum == 10000;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}