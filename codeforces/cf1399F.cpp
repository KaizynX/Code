/*
 * @Author: Kaizyn
 * @Date: 2021-01-04 20:12:36
 * @LastEditTime: 2021-01-05 10:25:55
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
const int N = 3e3+7;
const int M = 6e3+7;

int n, m;
int l[N], r[N], dp[M][M];
vector<int> a[M];

void discrete() {
  vector<int> d;
  for (int i = 1; i <= n; ++i) {
    d.emplace_back(l[i]);
    d.emplace_back(r[i]);
  }
  sort(d.begin(), d.end());
  d.erase(unique(d.begin(), d.end()), d.end());
  m = d.size();
  for (int i = 1; i <= n; ++i) {
    l[i] = lower_bound(d.begin(), d.end(), l[i])-d.begin()+1;
    r[i] = lower_bound(d.begin(), d.end(), r[i])-d.begin()+1;
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> l[i] >> r[i];
  }
  discrete();
  for (int i = 1; i <= n; ++i) {
    a[r[i]].emplace_back(l[i]);
  }
  for (int j = 1; j <= m; ++j) {
    for (int i = j; i; --i) {
      dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
    }
    sort(a[j].begin(), a[j].end());
    reverse(a[j].begin(), a[j].end());
    for (int &k : a[j]) { // [k, j]
      for (int i = 1; i <= k; ++i) {
        dp[i][j] = max(dp[i][j], dp[i][k-1]+1+dp[k][j]);
      }
    }
    #ifdef DEBUG
    for (int &k : a[j]) cout << k << ",";
    cout << endl;
    for (int i = 1; i <= j; ++i) {
      cout << dp[i][j] << " \n"[i==j];
    }
    #endif
  }
  cout << dp[1][m] << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 1; i <= m; ++i) {
      a[i].clear();
      for (int j = 1; j <= m; ++j) {
        dp[i][j] = 0;
      }
    }
  }
  return 0;
}
/*
1
7
1 10
2 8
2 5
3 4
4 4
6 8
7 7
*/