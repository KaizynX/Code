/*
 * @Author: Kaizyn
 * @Date: 2021-07-17 12:55:57
 * @LastEditTime: 2021-07-17 16:46:46
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

ll s[N];

int check(int x) {
  int has = 1, sum = 0;
  while (x) {
    int b = x%10;
    x /= 10;
    sum = (sum+b)%3;
    if ((has>>sum)&1) return true;
    has |= 1<<sum;
  }
  return false;
}

void init() {
  for (int i = 1; i <= 1e4; ++i) {
    s[i] = check(i)+s[i-1];
  }
}

ll f(ll x) {
  if (x <= 10000) return s[x];
  return s[10000]+x-10000;
}

inline void solve() {
  ll L, R;
  cin >> L >> R;
  cout << f(R)-f(L-1) << '\n';
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