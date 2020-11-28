/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 19:01:59
 * @LastEditTime: 2020-10-25 19:16:53
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

int n;
int a[10], b[N];
set<int> c[N];
set<pii> st;

inline void solve() {
  for (int i = 1; i <= 6; ++i) cin >> a[i];
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> b[i];
  // sort(a+1, a+7);
  // sort(b+1, b+n+1);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= 6; ++j) {
      c[i].insert(b[i]-a[j]);
    }
    st.insert({*c[i].begin(), i});
  }
  int res = INF;
  do {
    res = min(res, st.rbegin()->first-st.begin()->first);
    int id = st.begin()->second;
    c[id].erase(c[id].begin());
    if (c[id].empty()) break;
    st.erase(st.begin());
    st.insert({*c[id].begin(), id});
  } while (true);
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