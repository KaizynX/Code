/*
 * @Author: Kaizyn
 * @Date: 2021-03-21 20:56:51
 * @LastEditTime: 2021-03-21 21:28:33
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

int n, m;
int cnt[N];
vector<int> f[N];

inline void solve() {
  cin >> n >> m;
  memset(cnt+1, 0, sizeof(int)*n);
  int flag = 1;
  for (int i = 1, k; i <= m; ++i) {
    cin >> k;
    f[i].resize(k);
    for (int j = 0; j < k; ++j) cin >> f[i][j];
    if (k == 1) ++cnt[f[i][0]];
    if (cnt[f[i][0]] > (m+1)/2) flag = 0;
  }
  if (!flag) return cout << "NO\n", void();
  cout << "YES\n";
  for (int i = 1, c; i <= m; ++i) {
    if ((int)f[i].size() == 1) {
      c = f[i][0];
    } else {
      for (int &j : f[i]) {
        if (cnt[j]+1 <= (m+1)/2) {
          c = j;
          ++cnt[j];
          break;
        }
      }
    }
    cout << c << " \n"[i==m];
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