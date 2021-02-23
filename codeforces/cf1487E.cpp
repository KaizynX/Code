/*
 * @Author: Kaizyn
 * @Date: 2021-02-18 09:28:01
 * @LastEditTime: 2021-02-18 09:44:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 5e8;
// const ll INF = 1e18;
const int N = 2e5+7;

int n[4], m[3];
int a[4][N], dp[4][N];
vector<int> e[4][N];
set<pii> st;

inline void solve() {
  for (int i = 0; i < 4; ++i) cin >> n[i];
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < 3; ++i) {
    cin >> m[i];
    for (int j = 0, x, y; j < m[i]; ++j) {
      cin >> x >> y;
      --x; --y;
      e[i][y].emplace_back(x);
    }
  }
  for (int j = 0; j < n[0]; ++j) dp[0][j] = a[0][j];
  for (int i = 1; i < 4; ++i) {
    st.clear();
    st.insert({INF, -1});
    for (int j = 0; j < n[i-1]; ++j) st.insert({dp[i-1][j], j});
    for (int j = 0; j < n[i]; ++j) {
      for (int &x : e[i-1][j]) st.erase(st.find({dp[i-1][x], x}));
      dp[i][j] = st.begin()->first+a[i][j];
      for (int &x : e[i-1][j]) st.insert({dp[i-1][x], x});
    }
  }
  int res = INF;
  for (int j = 0; j < n[3]; ++j) res = min(res, dp[3][j]);
  cout << (res >= INF ? -1 : res) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}