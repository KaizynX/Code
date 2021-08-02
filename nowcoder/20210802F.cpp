/*
 * @Author: Kaizyn
 * @Date: 2021-08-02 12:28:16
 * @LastEditTime: 2021-08-02 12:39:04
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

int n, m;
pii a[N];
vector<array<ll, 3>> res[N];

bool check(ll x) {
  ll rest = x;
  for (int i = 1, j = 1; i <= n; ++i) {
    if (rest < a[i].first) {
      if (++j > m) return false;
      rest += x;
    }
    rest -= a[i].first;
  }
  return true;
}

void print(ll x) {
  ll p = 0;
  for (int i = 1, j = 1; i <= n; ++i) {
    int id = a[i].second;
    int t = a[i].first;
    if (p+t > x) {
      res[id].emplace_back(array<ll, 3>{j+1, 0, p+t-x});
    }
    res[id].emplace_back(array<ll, 3>{j, p, min(p+t, x)});
    p += t;
    if (p >= x) {
      ++j;
      p -= x;
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << res[i].size();
    for (auto j : res[i]) {
      cout << ' ' << j[0] << ' ' << j[1] << ' ' << j[2];
    }
    cout << '\n';
  }
}

inline void solve() {
  cin >> n >> m;
  ll l, r = 0, mid;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
    r += a[i].first;
    res[i].clear();
  }
  sort(a+1, a+n+1);
  reverse(a+1, a+n+1);
  l = a[1].first;
  while (l < r) {
    mid = (l+r)/2;
    if (check(mid)) r = mid;
    else l = mid+1;
  }
  print(l);
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