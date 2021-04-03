/*
 * @Author: Kaizyn
 * @Date: 2021-04-03 22:13:33
 * @LastEditTime: 2021-04-03 23:06:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e2+7;

int n;
int a[N*N];
int c[N][N];
vector<pii> p[2];

inline void solve() {
  cin >> n;
  p[0].clear();
  p[1].clear();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      p[(i+j)&1].emplace_back(i, j);
    }
  }
  for (int i = 1, f1 = 1, f2 = 2, p1 = 0, p2 = 1, a, b, x, y; i <= n*n; ++i) {
    cin >> a;
    if (a != f1) {
      b = f1;
      x = p[p1].back().first;
      y = p[p1].back().second;
      p[p1].pop_back();
    } else if (a != f2) {
      b = f2;
      x = p[p2].back().first;
      y = p[p2].back().second;
      p[p2].pop_back();
    }
    if (p[p1].empty()) {
      f1 = 3;
      p1 = 1;
    }
    if (p[p2].empty()) {
      f2 = 3;
      p2 = 0;
    }
    cout << b << ' ' << x << ' ' << y << endl;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}