/*
 * @Author: Kaizyn
 * @Date: 2020-12-06 22:31:43
 * @LastEditTime: 2020-12-06 22:45:36
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

struct Node {
  int x, y;
};

int n, k;
Node a[N];

int dis(Node n1, Node n2) {
  return abs(n1.x-n2.x)+abs(n1.y-n2.y);
}

inline void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
  }
  for (int i = 1; i <= n; ++i) {
    int flag = 1;
    for (int j = 1; j <= n; ++j) {
      flag &= dis(a[i], a[j]) <= k;
    }
    if (flag) return cout << 1 << endl, void();
  }
  cout << -1 << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}