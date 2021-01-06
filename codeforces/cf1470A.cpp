/*
 * @Author: Kaizyn
 * @Date: 2021-01-05 21:22:53
 * @LastEditTime: 2021-01-05 22:53:10
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
int a[N], b[N], c[N];
vector<int> p;

inline void solve() {
  p.clear();
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = 0;
  }
  sort(a+1, a+n+1);
  for (int i = 1; i <= m; ++i) {
    cin >> c[i];
  }
  ll res = 0;
  for (int i = 1; i <= n; ++i) {
    res += c[a[i]];
  }
  for (int i = 1; i <= m; ++i) {
    int j = upper_bound(a+1, a+n+1, i)-a;
    if (j > n) break;
    b[j] = 1;
    res += c[i]-c[a[j]];
    p.emplace_back(j);
  }
  for (int i = n; i; --i) {
    if (b[i]) continue;
    while (p.size() && p.back() > i) p.pop_back();
    if (p.size()) {
      int j = p.back();
      b[j] = 0;
      res += c[a[j]]-c[a[i]];
      p.pop_back();
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