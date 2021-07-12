/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 17:14:44
 * @LastEditTime: 2021-07-12 18:35:42
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

#define umap unordered_map

int n, d[3];
int a[N][3];
umap<int, umap<int, umap<int, int>>> mp;

inline bool check(int i, int j) {
  for (int k = 0; k < 3; ++k) {
    if (abs(a[i][k]-a[j][k]) > d[k]) return false;
  }
  return true;
}

inline int solve() {
  cin >> n;
  for (int i = 0; i < 3; ++i) cin >> d[i];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) cin >> a[i][j];
  }
  int b[3];
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 3; ++j) b[j] = a[i][j]/d[j];
    for (int x = b[0]-1; x <= b[0]+1; ++x)
    for (int y = b[1]-1; y <= b[1]+1; ++y)
    for (int z = b[2]-1; z <= b[2]+1; ++z) {
      int j = mp[x][y][z];
      if (!j) continue;
      if (check(i, j)) return i;
    }
    mp[b[0]][b[1]][b[2]] = i;
  }
  return 0;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << solve() << '\n';
  }
  return 0;
}