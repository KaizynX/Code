/*
 * @Author: Kaizyn
 * @Date: 2021-04-10 09:22:57
 * @LastEditTime: 2021-04-10 09:40:49
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
const int N = 1e2+7;

struct Euler {
  vector<int> prime;
  vector<bool> check;
  bool operator [](const int &i) { return check[i]; }
  void init(int n) {
    prime.clear();
    check = vector<bool>(n+1, true);
    check[1] = false;
    for (int i = 2; i <= n; ++i) {
      if (check[i]) prime.emplace_back(i);
      for (const int &j : prime) {
        if (i*j > n) break;
        check[i*j] = false;
        if (i%j == 0) break;
      }
    }
  }
} E;

int n;
ll sum;
ll p[N], t[N];

inline bool check(ll x) {
  ll tmp = 0, y = x;
  for (int &p : E.prime) {
    while (y%p == 0) y /= p, tmp += p;
  }
  if (y > 1) return false;
  return x == sum-tmp;
}

inline ll solve() {
  cin >> n;
  sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i] >> t[i];
    sum += p[i]*t[i];
  }
  for (ll r = sum; r > max(0ll, sum-10000); --r) {
    if (check(r)) return r;
  }
  return 0;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  E.init(500);
  assert(E.prime.size() == 95);
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    ll res = solve();
    cout << "Case #" << t << ": " << res << '\n';
  }
  return 0;
}