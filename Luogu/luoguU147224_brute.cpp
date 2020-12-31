/*
 * @Author: Kaizyn
 * @Date: 2020-12-27 13:27:47
 * @LastEditTime: 2020-12-27 13:30:15
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
const int N = 2e5+7;

struct Node {
  int x, t;
  bool operator <(const Node &b) const {
    return t < b.t;
  }
};

int n, k;
int dp[N];
Node a[N];

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].x >> a[i].t;
  }
  sort(a+1, a+n+1);
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    for (int j = 1; j < i; ++j) {
      if (abs(a[i].x-a[j].x) <= 1ll*k*(a[i].t-a[j].t)) {
        dp[i] = max(dp[i], dp[j]+1);
        res = max(res, dp[i]);
      }
    }
  }
  cout << res << endl;
  return 0;
}