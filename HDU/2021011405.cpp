/*
 * @Author: Kaizyn
 * @Date: 2021-01-14 10:16:13
 * @LastEditTime: 2021-01-14 10:24:39
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
const int N = 1e2+7;
const int dir[] = {0, -1, 0, 1, 0};

struct DSU {
  int fa[100000], num[100000];
  void init(int n) { for (int i = 0; i <= n; ++i) fa[i] = i, num[i] = 1; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) {
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    if (num[fx] >= num[fy]) num[fx] += num[fy], fa[fy] = fx;
    else num[fy] += num[fx], fa[fx] = fy;
    return true;
  }
};

int n, m;
char a[N][N];
DSU dsu;

int magic(int x, int y) {
  return x*n+y;
}

inline void solve() {
  dsu.init(n*n+n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i]+1);
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      for (int d = 0; d < 4; ++d) {
        int x = i+dir[d];
        int y = j+dir[d+1];
        if (x < 1 || y < 1 || x > n || y > n) continue;
        if (a[x][y] != a[i][j]) dsu.merge(magic(i, j), magic(x, y));
      }
    }
  }
  for (int _ = m, x, y; _; --_) {
    scanf("%d%d", &x, &y);
    printf("%d\n", dsu.num[dsu[magic(x, y)]]);
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  while (scanf("%d%d", &n, &m) == 2) solve();
  return 0;
}