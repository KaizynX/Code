/*
 * @Author: Kaizyn
 * @Date: 2021-02-04 16:40:43
 * @LastEditTime: 2021-02-04 18:05:57
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;
const int M = 27*27*27*27;

int n, m, k;
int p[N], mt[N], rk[N], vis[M], cnt[M], cmt[N], res[N];
string s[N];
// vis[i] the earlist position string(i) could appear

inline int myHash(const string &str, int bit = 0) {
  // [a, z]->[1, 26], [_]->[0]
  int h = 0;
  for (int i = 0; i < k; ++i) {
    if (((bit>>i)&1) || str[i] == '_') h = h*27;
    else h = h*27+str[i]-'a'+1;
  }
  return h;
}

/*
inline bool cmp(const string &x, const string &y) {
  for (int i = 0; i < k; ++i) {
    if (x[i] == y[i] || x[i] == '_' || y[i] == '_') continue;
    return false;
  }
  return true;
}
*/

inline void solve() {
  string str;
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> str;
    p[i] = myHash(str);
    vis[p[i]] = 1;
  }
  for (int i = 1; i <= m; ++i) {
    cin >> s[i] >> mt[i];
    ++cmt[mt[i]];
    for (int b = 0; b < 1<<k; ++b) {
      int h = myHash(s[i], b);
      if (vis[h]) vis[h] = max(vis[h], mt[i]);
    }
  }
  for (int i = 1; i <= m; ++i) {
    int flag = 0;
    for (int b = 0; b < 1<<k; ++b) {
      int h = myHash(s[i], b);
      if (vis[h] == mt[i]) ++cnt[h], flag = 1;
    }
    if (!flag) return cout << "NO\n", void();
  }
  iota(rk+1, rk+n+1, 1);
  /*
  sort(rk+1, rk+n+1, [&](int x, int y) {
    return vis[p[x]] < vis[p[y]];
  });
  */
  sort(rk+1, rk+n+1, [&](int x, int y) {
    return vis[p[x]] == vis[p[y]] ? cnt[p[x]] < cnt[p[y]] : vis[p[x]] < vis[p[y]];
  });
  #ifdef DEBUG
  for (int _ = 1, i; _ <= n; ++_) {
    i = rk[_];
    cout << i << " " << vis[p[i]] << " " << cnt[p[i]] << '\n';
  }
  #endif
  for (int _ = n, i, j = n, t; _; --_) {
    i = rk[_];
    t = vis[p[i]];
    if (!res[t]) {
      res[t] = i;
      if (cmt[t] != cnt[p[i]]) return cout << "NO\n", void();
    } else {
      while (res[j]) --j;
      if (j < t) return cout << "NO\n", void();
      res[j] = i;
    }
  }
  // if (!check()) return cout << "NO\n", void();
  cout << "YES\n";
  for (int i = 1; i <= n; ++i) cout << res[i] << " \n"[i==n];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}