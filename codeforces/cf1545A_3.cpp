/*
 * @Author: Kaizyn
 * @Date: 2021-07-12 00:20:46
 * @LastEditTime: 2021-07-12 12:41:42
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

int n;
int a[N], c[N][2];

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++c[a[i]][i&1];
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    if (--c[a[i]][i&1] < 0) return false;
  }
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
    for (int i = 1; i <= n; ++i) {
      c[a[i]][0] = c[a[i]][1] = 0;
    }
  }
  return 0;
}