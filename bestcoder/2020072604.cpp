/*
 * @Author: Kaizyn
 * @Date: 2020-07-26 14:12:21
 * @LastEditTime: 2020-07-26 14:20:58
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

struct Node {
  int x, y;
};

int n;
int vis[N];
Node a[N];

inline void solve() {
  cin >> n;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].y;
    if (a[i].x == 1) {
      vis[a[i].y] = 1;
      res = max(res, a[i].y+1);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i].x == 1) continue;
    if (!vis[a[i].y+1]) res = max(res, a[i].y+2);
    else res = max(res, a[i].y+3);
  }
  cout << res << endl;
  for (int i = 1; i <= n; ++i) {
    vis[a[i].y] = 0;
  }
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