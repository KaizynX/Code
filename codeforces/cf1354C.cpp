/*
 * @Author: Kaizyn
 * @Date: 2020-05-17 16:43:55
 * @LastEditTime: 2020-05-17 18:40:34
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e2+7;

int n;

inline void solve() {
  double res = 0;
  // cin >> n;
  scanf("%d", &n);
  if (n%2 == 0) {
    res = tan((n-1)*PI/n/2);
  } else {
    double h, theta, l, a, cost;
    l = 0.5/sin(PI/n/2);
    for (int i = 1; i <= n/2; ++i) {
      theta = PI/n*i;
      cost = cos(theta);
      a = sqrt(2*(1-cost*cost))*l;
      h = cost*l+a/sqrt(2);
      res = max(res, h);
    }
    res = 2*res/sqrt(2);
  }
  printf("%.9f\n", res);
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}