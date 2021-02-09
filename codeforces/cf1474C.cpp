/*
 * @Author: Kaizyn
 * @Date: 2021-02-05 16:41:52
 * @LastEditTime: 2021-02-05 16:48:05
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
const int N = 2e3+7;

int n;
int a[N];

bool check(int x, int print = 0) {
  multiset<int> s(a+1, a+n+1);
  if (print) cout << "YES\n" << x << '\n';
  while (s.size()) {
    int y = *s.rbegin();
    s.erase(--s.end());
    auto it = s.find(x-y);
    if (it == s.end()) return false;
    s.erase(it);
    if (print) cout << y << " " << x-y << endl;
    x = y;
  }
  return true;
}

inline void solve() {
  cin >> n;
  n *= 2;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a+1, a+n+1);
  for (int i = 1; i < n; ++i) {
    if (check(a[i]+a[n])) {
      return check(a[i]+a[n], 1), void();
    }
  }
  cout << "NO\n";
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