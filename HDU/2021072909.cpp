/*
 * @Author: Kaizyn
 * @Date: 2021-07-29 12:18:17
 * @LastEditTime: 2021-07-29 13:01:26
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
const int dir[] = {0, 1, 0, -1, 0};

int L, R;
char a[N][N];
int vis[N][N];
vector<pii> res;

void dfs(int x, int y) {
  // if (vis[x][y]) continue;
  vis[x][y] = 1;
  L = min(L, y);
  R = max(R, y);
  for (int i = 0, nx, ny; i < 4; ++i) {
    nx = x+dir[i];
    ny = y+dir[i+1];
    if (nx < 1 || ny < 1 || nx > 30 || ny > 100 || vis[nx][ny] || a[nx][ny] == '.') continue;
    dfs(nx, ny);
  }
}

inline void solve() {
  for (int i = 1; i <= 30; ++i) {
    scanf("%s", a[i]+1);
    for (int j = 1; j <= 100; ++j) {
      vis[i][j] = 0;
    }
  }
  res.clear();
  /*
  for (int i = 1, flag = 0; i <= 100; ++i) {
    for (int j = 1; j <= 30; ++j) {
      if (a[j][i] == '.') continue;
      if (vis[j][i]) continue;
      L = 1000;
      R = 0;
      dfs(j, i);
      if (!flag) for (int k = L; k <= L+10; ++k) {
        for (int l = 1; l <= 30; ++l) {
          if (!vis[l][k] && a[l][k] == '#') {
            dfs(l, k);
          }
        }
      }
      flag = 1;
      printf("%d %d\n", L, R);
    }
  }
  */
  for (int j = 100, cnt = 0; j; --j) {
    for (int i = 1; i <= 30; ++i) {
      if (a[i][j] == '#' && !vis[i][j]) {
        L = 1000;
        R = 0;
        dfs(i, j);
        res.emplace_back(L, R);
        // cout << cnt << ' ' << L << ' ' << R << '\n';
        if (++cnt >= 6) break;
      }
      if (cnt >= 6) break;
    }
  }
        L = 1000;
        R = 0;
  for (int i = 1; i <= 30; ++i) {
    for (int j = 1; j <= 100; ++j) {
      if (!vis[i][j] && a[i][j] == '#') {
        dfs(i, j);
      }
    }
  }
  res.emplace_back(L, R);
  sort(res.begin(), res.end());
  for (auto i : res) printf("%d %d\n", i.first, i.second);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("Case #%d:\n", t);
    solve();
  }
  return 0;
}