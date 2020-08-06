/*
 * @Author: Kaizyn
 * @Date: 2020-07-30 13:06:22
 * @LastEditTime: 2020-07-30 13:19:33
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

struct Node {
  int t, x;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return lhs.t < rhs.t;
  }
};

int n;
Node a[N];
map<int, int> w, e;
map<int, set<int>> uw, ue;

inline void solve() {
  w.clear(); e.clear();
  uw.clear(); ue.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].t >> a[i].x;
  }
  sort(a+1, a+n+1); // ?
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    int ww = a[i].x-a[i].t, ee = a[i].x+a[i].t;
    if (w[ww]) {
      continue;
    } else if (e[ee]) {
      continue;
    } else if (uw[ww].size()) {
      int j = *uw[ww].begin();
      uw[ww].erase(uw[ww].begin());
      int k = a[j].x+a[j].t;
      ue[k].erase(ue[k].find(j));
      w[ww] = 1;
    } else if (ue[ee].size()) {
      int j = *ue[ee].begin();
      ue[ee].erase(ue[ee].begin());
      int k = a[j].x-a[j].t;
      uw[k].erase(uw[k].find(j));
      e[ee] = 1;
    } else {
      ++res;
      uw[ww].insert(i);
      ue[ee].insert(i);
    }
  }
  cout << res << endl;
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