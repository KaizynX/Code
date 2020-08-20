/*
 * @Author: Kaizyn
 * @Date: 2020-08-12 22:31:41
 * @LastEditTime: 2020-08-12 23:04:16
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

int n, d, m;
int a[N];
long long sum[2][N];
vector<int> b[2];

inline void solve() {
  cin >> n >> d >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[a[i] > m].emplace_back(a[i]);
  }
  for (int k = 0; k < 2; ++k) {
    sort(b[k].begin(), b[k].end());
    reverse(b[k].begin(), b[k].end());
    sum[k][0] = 0;
    for (int i = 0; i < (int)b[k].size(); ++i) {
      sum[k][i+1] = sum[k][i]+b[k][i];
    }
  }
  long long res = sum[0][b[0].size()];
  for (int i = 0; i < (int)b[1].size(); ++i) {
    // choose i+1's b[1]
    if (i*(d+1)+1 > n) break;
    int rest = min((int)b[0].size(), n-i*(d+1)-1);
    // if (rest > (int)b[0].size()) continue;
    #ifdef DEBUG
    cout << i << " " << rest << " " << sum[1][i+1] << " " << sum[0][rest] << endl;
    #endif
    res = max(res, sum[1][i+1]+sum[0][rest]);
  }
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}