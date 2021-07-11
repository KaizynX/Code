/*
 * @Author: Kaizyn
 * @Date: 2021-07-11 17:50:40
 * @LastEditTime: 2021-07-11 17:53:17
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
const int N = 3e5+7;

struct Tree {
  struct TreeNode {
    int l, r;
    int g[2]; // r+1不选/选时l选不选
    int c[2]; // r+1不选/选时中间选了几个
    ll s[2];  // r+1不选/选时中间选的和
  }
};

int n, m;
pii a[N];

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  cin >> m;
  for (int i = 1; i <= n; ++i) {
    ;
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