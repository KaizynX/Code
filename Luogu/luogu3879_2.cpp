/*
 * @Author: Kaizyn
 * @Date: 2021-08-18 14:28:36
 * @LastEditTime: 2021-08-18 15:03:51
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e3+7;
const int M = 1e4+7;

struct TireTree {
  static const int SZ = 26;
  char beg;
  int cnt;
  vector<array<int, SZ>> nex;
  vector<vector<int>> exist;
  TireTree(char _beg = 'a') : beg(_beg) { clear(); }
  void clear() {
    // memset(nex, 0, sizeof nex);
    // memset(exist, 0, sizeof exist);
    nex.assign(1, array<int, SZ>());
    exist.assign(1, vector<int>());
    cnt = 0;
  }
  void insert(const string &s, int id) {
    int len = s.size(), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) {
        nex[p][c] = ++cnt;
        nex.emplace_back(array<int, SZ>());
        exist.emplace_back(vector<int>());
      }
      p = nex[p][c];
    }
    if (exist[p].empty() || exist[p].back() != id) exist[p].emplace_back(id);
  }
  vector<int> query(const string &s) {
    int len = s.size(), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) return exist[0];
      p = nex[p][c];
    }
    return exist[p];
  }
};

int n, m;
string s;
TireTree tire;

inline void solve() {
  cin >> n;
  for (int i = 1, l; i <= n; ++i) {
    cin >> l;
    for (int j = 1; j <= l; ++j) {
      cin >> s;
      tire.insert(s, i);
    }
  }
  cin >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> s;
    auto v = tire.query(s);
    if (v.empty()) cout << '\n';
    for (int j = 0; j < (int)v.size(); ++j) {
      cout << v[j] << " \n"[j+1 == (int)v.size()];
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}