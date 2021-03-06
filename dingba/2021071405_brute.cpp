/*
 * @Author: Kaizyn
 * @Date: 2021-07-14 14:52:16
 * @LastEditTime: 2021-07-14 14:53:16
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
const int N = 5e5+7;

struct Node {
  int x, y;
};

int n;
Node a[N];

inline ll dis(int i, int j) {
  return ll(a[i].x-a[j].x)*(a[i].x-a[j].x)+ll(a[i].y-a[j].y)*(a[i].y-a[j].y);
}

inline void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 0; i < n; ++i) {
    int k = 0;
    for (int j = 0; j < n; ++j) {
      if (dis(i, j) > dis(i, k)) k = j;
    }
    cout << k+1 << '\n';
  }
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