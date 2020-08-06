/*
 * @Author: Kaizyn
 * @Date: 2020-07-22 00:18:51
 * @LastEditTime: 2020-07-22 11:03:13
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

int n, x, y;
int a[N], b[N], cnt[N];
vector<int> p[N];
set<pii> st;

inline void solve() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    p[b[i]].emplace_back(i);
    ++cnt[b[i]];
  }

  y -= x;
  for (int i = 1; i <= n+1; ++i) {
    if (p[i].size()) st.insert({p[i].size(), i});
    else a[0] = i;
  }
  for (int i = 1; i <= n; ++i) a[i] = a[0];
  while (x && st.size()) {
    auto it = --st.end();
    int k = it->second;
    st.erase(it);
    a[p[k].back()] = k;
    p[k].pop_back();
    --cnt[k];
    if (p[k].size()) st.insert({p[k].size(), k});
    --x;
  }
  for (int i = 1; i <= n+1 && y; ++i) {
    if (p[i].size()) st.erase({p[i].size(), i});
    while (cnt[i] && st.size() && y) {
      auto it = --st.end();
      int k = it->second;
      st.erase(it);
      a[p[k].back()] = i;
      p[k].pop_back();
      --cnt[i];
      if (p[k].size()) st.insert({p[k].size(), k});
      --y;
    }
    if (p[i].size()) st.insert({p[i].size(), i});
  }
  if (x || y) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
    cout.flush();
  }
  // clear
  st.clear();
  for (int i = 1; i <= n+1; ++i) {
    vector<int>().swap(p[i]);
    cnt[i] = 0;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
1
6 5 6
3 3 1 1 1 1
*/