/*
 * @Author: Kaizyn
 * @Date: 2020-12-30 22:33:12
 * @LastEditTime: 2020-12-30 22:45:58
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

int n;
int b[N], c[N];

inline void solve() {
  cin >> n;
  // memset(b+1, 0, sizeof(int)*n*2);
  // memset(c+1, 0, sizeof(int)*n*2);
  for (int i = 1; i <= n*2+1; ++i) {
    b[i] = c[i] = 0;
  }
  for (int i = 1, a; i <= n; ++i) {
    cin >> a;
    ++b[a];
  }
  int res = 0;
  for (int i = 1; i <= 2*n+1; ++i) {
    if (c[i] || b[i]) ++res;
    if ((c[i] && b[i]) || b[i] > 1) c[i+1] = 1;
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}