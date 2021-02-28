/*
 * @Author: Kaizyn
 * @Date: 2021-02-25 21:41:05
 * @LastEditTime: 2021-02-25 21:57:59
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

int x, y;
double v1, v2;
double t[N];

double calc(int a, int b) {
  return a/v1+sqrt((x-a)*(x-a)+b*b)/log(1+t[a]*b)+(y-b)/v2;
}

inline void solve() {
  int a, b, c, p;
  scanf("%d%d%lf%lf", &x, &y, &v1, &v2);
  scanf("%d%d%d%d",&a,&b,&c,&p);
  for (int i=0; i<x; i++){
    t[i]=(double)a/c;
    a=(long long)a*b%p;
  }
  double res = x/v1+y/v2;
  for (int i = 0; i < x; ++i) {
    if (y <= 10000) for (int j = 1; j <= y; ++j) {
      res = min(res, calc(i, j));
    }
  }
  for (int i = 1; i < y; ++i) {
    res = min(res, calc(0, i));
    res = min(res, calc(x-1, i));
  }
  printf("%.4f\n", res);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}