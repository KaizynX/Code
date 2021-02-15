/*
 * @Author: Kaizyn
 * @Date: 2021-02-09 19:45:16
 * @LastEditTime: 2021-02-09 19:50:11
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int M1 = 998244353;
const int M2 = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

int n;
int a[N], vis[N];
ll h1, h2;
map<pii, int> cnt;

template <typename T>
T exgcd(const T a, const T b, T &x, T &y) {
  if (!b) return x = 1, y = 0, a;
  T d = exgcd(b, a%b, y, x);
  y -= a/b*x;
  return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo) {
  T x, y;
  exgcd(a, mo, x, y);
  return (x%mo+mo)%mo;
}

void update(int x) {
  if (vis[x]) {
    (h1 *= mul_inverse(x, M1)) %= M1;
    (h2 *= mul_inverse(x, M2)) %= M2;
  } else {
    (h1 *= x) %= M1;
    (h2 *= x) %= M2;
  }
  vis[x] ^= 1;
}

inline void solve() {
  cin >> n;
  ll res = 0;
  h1 = h2 = 1;
  cnt[{h1, h2}] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    for (int j = 2; j*j <= a[i]; ++j) {
      if (a[i]%j) continue;
      int k = 0;
      while (a[i]%j == 0) a[i] /= j, ++k;
      if (k&1) update(j);
    }
    if (a[i]) update(a[i]);
    res += cnt[{h1, h2}];
    ++cnt[{h1, h2}];
  }
  cout << res << '\n';
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