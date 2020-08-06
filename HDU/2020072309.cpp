/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 16:46:14
 * @LastEditTime: 2020-07-23 16:55:42
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e2+7;

int n, m, q, res;
int a[N][N];
int cnt[N*N];
vector<int> p[N];

void discrete() {
  static vector<int> dis;
  dis.clear();
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dis.emplace_back(a[i][j]);
    }
  }
  sort(dis.begin(), dis.end());
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      a[i][j] = lower_bound(dis.begin(), dis.end(), a[i][j])-dis.begin();
    }
  }
}

void add(int v) {
  for (int i = 1; i <= n; ++i) {
    sort(p[i].begin(), p[i].end());
    for (int k = 0; k < (int)p[i].size(); k += 2) {
      for (int j = p[i][k]+1; j <= p[i][k+1]; ++j) {
        if (cnt[a[i][j]] == 0) ++res;
        cnt[a[i][j]] += v;
        if (cnt[a[i][j]] == 0) --res;
      }
    }
  }
}

inline void solve() {
  cin >> n >> m >> q;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> a[i][j];
    }
  }
  discrete();
  string s;
  for (int i = 1, x, y; i <= q; ++i) {
    cin >> x >> y >> s;
    for (int j = 1; j <= n; ++j) p[j].clear();
    for (const char &c : s) {
      if (c == 'L') --x, p[x+1].emplace_back(y);
      if (c == 'R') ++x, p[x].emplace_back(y);
      if (c == 'U') ++y;
      if (c == 'D') --y;
    }
    add(1);
    cout << res << endl;
    add(-1);
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