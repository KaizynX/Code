/*
 * @Author: Kaizyn
 * @Date: 2021-08-02 12:13:13
 * @LastEditTime: 2021-08-02 12:14:39
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
const int N = 1e3+7;

int n, m;
pii a[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a+m);
  cout << m << '\n';
  for (int i = 0; i < m; ++i) {
    cout << a[(i+1)%m].first << ' ' << a[i].second << '\n';
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