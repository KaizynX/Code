/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 23:26:19
 * @LastEditTime: 2021-01-05 23:58:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 3e5+7;

int n, m;
int a[N], c[N];
vector<int> p;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) cin >> c[i];

  int k = 1;
  ll res = 0;
  p.clear();
  sort(a+1, a+n+1);
  for (int j = 1; k <= m; ++k) {
    j = upper_bound(a+j, a+n+1, k)-a;
    if (j > n) break;
    p.push_back(j++);
    res += c[k];
  }
  --k;
  for (int i = 1; i <= n; ++i) res += c[a[i]];
  for (int &i : p) res -= c[a[i]];
  for (int &i : p) {
    if (k && k > a[i]) {
      res += c[a[i]]-c[k--];
    }
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}