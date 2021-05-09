/*
 * @Author: Kaizyn
 * @Date: 2021-05-08 20:26:18
 * @LastEditTime: 2021-05-08 21:20:23
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n, m, l;
int a[N], b[N], c[N];
int la[N], ra[N], lb[N], rb[N];
int cnta[N], cntb[N], flag;

inline bool solve() {
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> b[i];
  for (int i = 1; i <= l; ++i) cin >> c[i];

  for (int i = 1, j = 1, k = 1; i <= l; ++i) {
    while (j <= n && a[j] != c[i]) ++j;
    while (k <= m && b[k] != c[i]) ++k;
    la[i] = j;
    lb[i] = k;
  }
  for (int i = l, j = n, k = m; i; --i) {
    while (j && a[j] != c[i]) --j;
    while (k && b[k] != c[i]) --k;
    ra[i] = j;
    rb[i] = k;
  }
  if (la[l] > n || lb[l] > m || ra[1] < 1 || rb[1] < 1) return false;

  la[0] = lb[0] = 0;
  ra[l+1] = n+1; rb[l+1] = m+1;
  flag = 0;
  for (int i = 1; i <= max({n, m, l}); ++i) cnta[i] = cntb[i] = 0;

  for (int i = 0, al = 1, ar = 0, bl = 1, br = 0, val; i <= l; ++i) {
    // between c[i] & c[i+1]
    assert(la[i] < ra[i+1]);
    assert(lb[i] < rb[i+1]);
    while (ar+1 < ra[i+1]) {
      val = a[++ar];
      if (cnta[val]++ == 0 && cntb[val] > 0) ++flag;
    }
    while (al <= la[i]) {
      val = a[al++];
      if (--cnta[val] == 0 && cntb[val] > 0) --flag;
    }
    while (br+1 < rb[i+1]) {
      val = b[++br];
      if (cntb[val]++ == 0 && cnta[val] > 0) ++flag;
    }
    while (bl <= lb[i]) {
      val = b[bl++];
      if (--cntb[val] == 0 && cnta[val] > 0) --flag;
    }
    assert(flag >= 0);
    if (flag) return false;
  }
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  while (cin >> n >> m >> l) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}