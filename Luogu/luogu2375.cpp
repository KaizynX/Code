/*
 * @Author: Kaizyn
 * @Date: 2021-08-18 13:46:24
 * @LastEditTime: 2021-08-18 14:10:32
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#define log(x) (31-__builtin_clz(x))
const int N = 1e6+7;
const int LOGN = log(N)+3;

inline void get_next(const string &s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

int n;
int nex[N], dep[N];
int fa[N][LOGN];
string s;

inline void solve() {
  cin >> s;
  n = s.size();
  get_next(s, nex);
  dep[0] = 0;
  for (int i = 0; i <= n; ++i) {
    fa[i][0] = nex[i];
    dep[i] = dep[nex[i]]+1;
    for (int j = 0; 1<<j < dep[i]; ++j) {
      fa[i][j+1] = fa[fa[i][j]][j];
    }
  }
  #ifdef DEBUG
  for (int i = 0; i <= n; ++i) cout << nex[i] << " \n"[i==n];
  for (int i = 0; i <= n; ++i) cout << dep[i] << " \n"[i==n];
  #endif
  ll res = 1;
  for (int i = 1, j, k; i <= n; ++i) {
    for (j = i, k = log(dep[i]); k >= 0; --k) {
      if (fa[j][k] > i/2) j = fa[j][k];
    }
    j = fa[j][0];
    #ifdef DEBUG
    cout << j << " \n"[i==n];
    #endif
    res = res*dep[j]%MOD;
  }
  cout << res << '\n';
  /*
  res = 1;
  for (int i = 1; i <= n; ++i) {
    int j = nex[i];
    while (j > i/2) j = nex[j];
    res = res*(j+1)%MOD;
    #ifdef DEBUG
    cout << j << " \n"[i==n];
    #endif
  }
  cout << res << '\n';
  */
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}