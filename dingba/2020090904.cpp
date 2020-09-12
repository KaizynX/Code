/*
 * @Author: Kaizyn
 * @Date: 2020-09-09 20:03:22
 * @LastEditTime: 2020-09-09 20:28:13
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 25;

int n, L, R;
int x[N], y[N];
double p[N], t[N];

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  // cin >> n >> L >> R;
  // for (int i = 1; i <= n; ++i) cin >> x[i];
  // for (int i = 1; i <= n; ++i) cin >> y[i];
  scanf("%d %d %d", &n, &L, &R);
  for (int i = 1; i <= n; ++i) scanf("%d", x+i);
  for (int i = 1; i <= n; ++i) scanf("%d", y+i);
  double gap = 1e-5;
  for (double M = L+gap; M < R; M += gap) {
    double winner = 0;
    double K = (R-M)/(M-L);
    for (int i = 1; i <= n; ++i) {
      if (x[i] <= M) {
        t[i] = (R-L)-((K*(M-x[i])+M)-x[i]);
      } else {
        t[i] = (R-L)-(x[i]-(M-(x[i]-M)/K));
      }
      t[i] += y[i];
      winner = max(winner, t[i]);
    }
    for (int i = 1; i <= n; ++i) {
      // if (abs(winner-t[i]) < eps) p[i] += gap/(R-L);
      if (winner == t[i]) p[i] += gap/(R-L);
    }
  }
  for (int i = 1; i <= n; ++i) printf("%.6f\n", p[i]);
  return 0;
}