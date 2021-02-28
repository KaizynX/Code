/*
 * @Author: Kaizyn
 * @Date: 2021-02-26 17:16:14
 * @LastEditTime: 2021-02-26 17:35:34
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

double f(ll a, ll b) {
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
    int l = 1, r = y, mid;
    while (l < r) {
      mid = (l+r)>>1;
      if (f(i, mid) < f(i, mid+1)) r = mid;
      else l = mid+1;
    }
    res = min(res, f(i, l));
  }
  printf("%.4f\n", res);
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}