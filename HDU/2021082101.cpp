/*
 * @Author: Kaizyn
 * @Date: 2021-08-21 13:03:46
 * @LastEditTime: 2021-08-21 13:06:55
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
const int N = 1e5+7;

int n, m;
int a[N];
multiset<int> b;

inline bool solve() {
  cin >> n >> m;
  b.clear();
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1, x; i <= m; ++i) cin >> x, b.insert(x);
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  for (int i = 1; i <= n; ++i) {
    auto it = b.lower_bound(a[i]);
    if (it == b.end()) return false;
    int x = *it-a[i];
    b.erase(it);
    if (x) b.insert(x);
  }
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}