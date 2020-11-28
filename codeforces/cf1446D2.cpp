/*
 * @Author: Kaizyn
 * @Date: 2020-11-16 21:55:30
 * @LastEditTime: 2020-11-16 23:30:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N];
vector<int> p[N];
map<int, int> last;

int calc(int D, int V) {
  if (p[V].empty()) return 0;
  int nd = p[D].size(), nv = p[V].size();
  last.clear();
  last[0] = 0;
  int res = 0, j = 0;
  int i = lower_bound(p[D].begin(), p[D].end(), p[V].front())-p[D].begin();
  int s = i, cur;
  while (i < nd || j < nv) {
    if (i >= nd || (j < nv && p[V][j] < p[D][i])) {
      cur = p[V][j];
      if (a[cur-1] != D && a[cur-1] != V) {
        if (last.count(s)) res = max(res, cur-1-last[s]);
      }
      --s;
      ++j;
      if (last.count(s)) res = max(res, cur-last[s]);
      else last[s] = cur;
    } else {
      cur = p[D][i];
      if (a[cur-1] != D && a[cur-1] != V) {
        if (last.count(s)) res = max(res, cur-1-last[s]);
      }
      ++s;
      ++i;
      if (last.count(s)) res = max(res, cur-last[s]);
      else last[s] = cur;
    }
  }
  return res;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];

  int mx = 0, D, V, mxt = 0;
  for (int i = 1; i <= n; ++i) {
    p[a[i]].emplace_back(i);
    if ((int)p[a[i]].size() > mx) {
      mx = p[a[i]].size();
      mxt = 1;
      D = a[i];
    } else if ((int)p[a[i]].size() == mx) {
      ++mxt;
      V = a[i];
    }
  }
  if (mxt > 1) return cout << calc(D, V) << endl, void();
  int res = 0;
  for (V = 1; V <= n; ++V) if (D != V) {
    res = max(res, calc(D, V));
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