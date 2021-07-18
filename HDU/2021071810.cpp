/*
 * @Author: Kaizyn
 * @Date: 2021-07-18 12:22:50
 * @LastEditTime: 2021-07-18 13:20:10
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
const int N = 1e5+7;

int n, m;
int lk[N][2], pt[N][2], sz[N];

void co(int x, int y) {
  int &lx = lk[x][1] ? lk[x][0] : lk[x][1];
  int &ly = lk[y][1] ? lk[y][0] : lk[y][1];
  lx = y;
  ly = x;
}

inline void solve() {
  // cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    lk[i][0] = lk[i][1] = 0;
    pt[i][0] = pt[i][1] = i;
    sz[i] = 1;
  }
  for (int i = 1, a, b; i <= m; ++i) {
    cin >> a >> b;
    if (!pt[a][0]) continue;
    if (pt[b][0]) {
      co(pt[b][1], pt[a][1]);
      pt[b][1] = pt[a][0];
    } else {
      pt[b][0] = pt[a][1];
      pt[b][1] = pt[a][0];
    }
    sz[b] += sz[a];
    sz[a] = 0;
    pt[a][0] = pt[a][1] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    cout << sz[i];
    for (int j = pt[i][1], l = 0, k; j; l = j, j = k) {
      cout << ' ' << j;
      k = lk[j][0] == l ? lk[j][1] : lk[j][0];
    }
    cout << '\n';
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  // int T = 1;
  // cin >> T; // scanf("%d", &T);
  // for (int t = 1; t <= T; ++t) {
    // solve();
  // }
  while (cin >> n >> m) solve();
  return 0;
}