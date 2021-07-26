/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 22:30:10
 * @LastEditTime: 2021-07-25 22:43:00
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e4+7;

int n;
int r[N][6];

bool cmp(int x, int y) {
  int cnt = 0;
  for (int j = 1; j <= 5; ++j) {
    cnt += r[x][j] < r[y][j];
  }
  return cnt >= 3;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 5; ++j) {
      cin >> r[i][j];
    }
  }
  int k = 1;
  for (int i = 2; i <= n; ++i) {
    if (cmp(i, k)) k = i;
  }
  int flag = 1;
  for (int i = 1; i <= n; ++i) {
    if (i == k) continue;
    if (cmp(i, k)) flag = 0;
  }
  cout << (flag ? k : -1) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}