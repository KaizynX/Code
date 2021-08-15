/*
 * @Author: Kaizyn
 * @Date: 2021-08-15 17:23:24
 * @LastEditTime: 2021-08-15 17:32:08
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
const int N = 1e6+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m;
int nex[N], del[N], mat[N];
string s, t;
DSU dsu;

inline void get_next(const string &s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline void solve() {
  cin >> s >> t;
  n = s.size();
  m = t.size();
  dsu.init(n);
  get_next(t, nex);
  for (int i = 0, j = 0, k; i < n; ++i) {
    while (j && s[i] != t[j]) j = nex[j];
    if (s[i] == t[j]) ++j;
    mat[i] = j;
    if (j == m) {
      for (k = i; j--; k = dsu[k-1]) {
        del[k] = 1;
        dsu.merge(k, k-1);
      }
      j = mat[k];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (del[i]) continue;
    cout << s[i];
  }
  cout << '\n';
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
/*
emomooo
moo
*/