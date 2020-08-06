/*
 * @Author: Kaizyn
 * @Date: 2020-07-26 13:59:35
 * @LastEditTime: 2020-07-26 14:03:49
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
int b[N];
double c[N];

inline void solve() {
  cin >> n;
  double res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i] >> c[i];
    res = max(res, (1-c[i])/(b[i]+1-c[i]));
  }
  printf("%.5f\n", res);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}