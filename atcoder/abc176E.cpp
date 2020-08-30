/*
 * @Author: Kaizyn
 * @Date: 2020-08-22 21:49:04
 * @LastEditTime: 2020-08-22 21:58:47
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

int n, m, t;
int cnt[N];
multiset<int> st;
map<int, vector<int>> mp;

inline void solve() {
  cin >> n >> m >> t;
  for (int i = 1, x, y; i <= t; ++i) {
    cin >> x >> y;
    mp[x].emplace_back(y);
    ++cnt[y];
  }
  for (int i = 1; i <= 300000; ++i) {
    if (cnt[i]) st.insert(cnt[i]);
  }
  int res = 0;
  for (auto &ppp : mp) {
    vector<int> &vec = ppp.second;
    for (const int &y : vec) {
      st.erase(st.find(cnt[y]));
      st.insert(--cnt[y]);
    }
    res = max(res, (int)vec.size()+*st.rbegin());
    for (const int &y : vec) {
      st.erase(st.find(cnt[y]));
      st.insert(++cnt[y]);
    }
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