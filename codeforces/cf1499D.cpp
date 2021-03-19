/*
 * @Author: Kaizyn
 * @Date: 2021-03-19 14:22:00
 * @LastEditTime: 2021-03-19 18:08:31
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
const int N = 2e7+7;

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

ll c, d, x, res;
int t[N];

void init() {
  E.init(2e7);
  for (int &i : E.prime) {
    for (int j = i; j <= 2e7; j += i) {
      ++t[j];
    }
  }
}

void f(ll g) {
  if ((x/g+d)%c) return;
  res += 1<<t[(x/g+d)/c];
  /*
  if ((x+d*g)%c == 0) {
    ll l = (x+d*g)/c;
    if (l%g == 0) res += 1<<t[l/g];
  }
  */
}

inline void solve() {
  res = 0;
  cin >> c >> d >> x;
  for (int i = 1; i*i <= x; ++i) {
    if (x%i) continue;
    f(i);
    if (i*i != x) f(x/i);
  }
  cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  init();
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}
/*
2
2 58 4
1 3205013 7694908

10
180
*/