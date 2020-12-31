/*
 * @Author: Kaizyn
 * @Date: 2020-12-31 00:16:27
 * @LastEditTime: 2020-12-31 00:37:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

int n, m;
int l[N], r[N], a[N];

inline void solve() {
  cin >> n >> m;
  // memset(a+1, 0, sizeof(int)*m);
  for (int i = 1, k; i <= n; ++i) {
    cin >> k;
    if (k == 1) {
      cin >> l[i];
      r[i] = l[i];
    } else {
      cin >> l[i] >> r[i];
      if (l[i] > r[i]) swap(l[i], r[i]);
    }
    int last = 0;
    for (int j; a[l[i]] && l[i] <= r[i]; ) {
      j = a[l[i]];
      l[i] = min(r[i], r[j])+1;
      r[i] = max(r[i], r[j]);
      // r[last] = r[j];
      r[last] = max(r[last], r[j]); // ??合并
      last = j;
    }
    if (l[i] <= r[i]) {
      a[l[i]] = i;
      // r[last] = r[i];
      r[last] = max(r[last], r[i]);
    }
  }
  vector<int> res;
  for (int i = 1; i <= m; ++i) {
    if (a[i]) res.emplace_back(a[i]);
  }
  sort(res.begin(), res.end());
  cout << qpow(2, res.size()) << " " << res.size() << endl;
  for (int &i : res) cout << i << " ";
  cout << endl;
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