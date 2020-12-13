/*
 * @Author: Kaizyn
 * @Date: 2020-12-06 22:32:05
 * @LastEditTime: 2020-12-06 23:38:09
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

int n;
int a[N], res[N];
vector<int> p[N];
set<int> st;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    p[a[i]].emplace_back(i);
  }
  res[0] = 1;
  st.insert(0); st.insert(n+1);
  for (int i = 1, width = n, flag = 1; i <= n; ++i) {
    int cur = 0, l, r;
    flag &= !p[i].empty();
    for (int &j : p[i]) {
      auto it = st.lower_bound(j);
      r = *it;
      l = *--it;
      cur = max(cur, r-l-1);
    }
    width = min(width, cur);
    res[n-i+1] = flag && width >= n-i+1;
    for (int &j : p[i]) st.insert(j);
  }
  for (int i = 1; i <= n; ++i) cout << res[i];
  cout << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    st.clear();
    for (int i = 1; i <= n; ++i) {
      p[i] = vector<int>();
    }
  }
  return 0;
}