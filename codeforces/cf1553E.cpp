/*
 * @Author: Kaizyn
 * @Date: 2021-07-22 23:16:25
 * @LastEditTime: 2021-07-22 23:18:43
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
const int N = 3e5+7;

int n, m;
int p[N];
vector<int> res;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> p[i];

  cout << res.size();
  for (int i : res) cout << ' ' << i;
  cout << '\n';
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