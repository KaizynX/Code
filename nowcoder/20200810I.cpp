/*
 * @Author: Kaizyn
 * @Date: 2020-08-10 16:00:10
 * @LastEditTime: 2020-08-10 16:14:21
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e3+7;

int n;
vector<pii> v;

int f(const vector<pii> &vec) {
  static int st[N], cnt[N];
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    st[i] = -1;
    cnt[i] = 0;
  }
  for (int i = 0; i < (int)vec.size(); ++i) {
    int x = vec[i].first, y = vec[i].second;
    if (st[x] == -1) st[x] = i;
    if (st[y] == -1) st[y] = i;
    if (++cnt[x] == n-1) res += i-st[x]+1;
    if (++cnt[y] == n-1) res += i-st[y]+1;
  }
  return res;
}

void print(const vector<pii> &vec) {
  for (const pii &p : vec) {
    cout << p.first << " " << p.second << endl;
  }
}


inline void solve() {
  cin >> n;
  /*
  v.clear();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < i; ++j) {
      v.emplace_back(j, i);
    }
  }
  cout << f(v) << endl;
  print(v);
  */
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      v.emplace_back(i, j);
    }
  }
  for (int i = 0, j, x, y; i < (int)v.size(); ++i) {
    x = v[i].first; y = v[i].second;
    j = i-1;
    if (x == 1) continue;
    if (y == n) {
      ;
    }
    while (j >= 0) {
      if (v[j].first == 1 && (v[j].second == x || v[j].second == y)) break;
      if (y == n && (v[j].first == x || v[j].second == x)) break;
    }
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