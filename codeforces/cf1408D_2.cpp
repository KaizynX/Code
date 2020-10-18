/*
 * @Author: Kaizyn
 * @Date: 2020-09-30 22:32:52
 * @LastEditTime: 2020-10-01 00:00:34
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e3+7;

struct Node {
  int x, y;
  bool operator <(const Node &nex) const {
    return x < nex.x;
  }
};

struct Change {
  int id, add, val;
  bool operator <(const Change &nex) const {
    return add < nex.add;
  }
};

int n, m;
int d[N];
Node r[N], s[N];
multiset<int> st;
vector<Change> cg;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> r[i].x >> r[i].y;
    ++r[i].x; ++r[i].y;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> s[i].x >> s[i].y;
    ++s[i].x; ++s[i].y;
  }
  sort(s+1, s+m+1);
  sort(r+1, r+n+1);
  int t = 0;
  for (int i = 1; i <= m; ++i) {
    if (s[i].x == s[t].x) {
      s[t].y = max(s[t].y, s[i].y);
    } else {
      s[++t] = s[i];
    }
  }
  s[t+1].y = 0;
  for (int i = t; i; --i) {
    s[i].y = max(s[i+1].y, s[i].y);
  }
  for (int i = 1; i <= n; ++i) {
    d[i] = max(0, s[1].y+1-r[i].y);
    for (int j = 1; j <= t; ++j) {
      if (r[i].x > s[j].x) {
        d[i] = max(0, s[j+1].y+1-r[i].y);
      } else {
        cg.push_back(Change{i, s[j].x+1-r[i].x, max(0, s[j+1].y+1-r[i].y)});
      }
    }
    st.insert(d[i]);
  }
  sort(cg.begin(), cg.end());
  int res = *st.rbegin();
  for (int i = 0, sz = cg.size(); i < sz; ++i) {
    st.erase(st.find(d[cg[i].id]));
    d[cg[i].id] = cg[i].val;
    st.insert(cg[i].val);
    res = min(res, cg[i].add+*st.rbegin());
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