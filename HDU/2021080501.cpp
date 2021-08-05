/*
 * @Author: Kaizyn
 * @Date: 2021-08-05 12:30:18
 * @LastEditTime: 2021-08-05 13:38:12
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
const int N = 2e7+40;

namespace STD {
  int L[N], R[N];

struct Euler {
  int tot;
  int prime[N];
  bool check[N];
  bool operator [](const int &i) { return check[i]; }
  void init(int n) {
    tot = 0;
    fill(check+2, check+n+1, 1);
    for (int i = 2; i <= n; ++i) {
      if (check[i]) prime[++tot] = i;
      for (int j = 1; j <= tot && i*prime[j] <= n; ++j) {
        check[i*prime[j]] = false;
        if (i%prime[j] == 0) break;
      }
    }
  }
} E;

void init() {
  E.init(N-1);
  int last = 0;
  for (int i = 10000019; i; ++i) {
    if (E[i]) {
      last = i;
      L[i] = R[i] = i;
      break;
    } else if (E[i+i+1]) {
      L[i] = i;
      R[i] = i+1;
      last = i;
      break;
    }
  }
  for (int i = 1e7+18; i; --i) {
    if (E[i]) {
      last = i;
      L[i] = R[i] = i;
    } else if (E[i+i+1]) {
      L[i] = i;
      R[i] = i+1;
      last = i;
    } else {
      L[i] = -L[last]+1;
      R[i] = R[last];
    }
  }
}


int solve(int x) {
  if (x == 0) return 3;
  if (x > 0) {
    int res = R[x]-L[x]+1;
    if (E[x+x-1]) res = min(res, 2);
    return res;
  }
  int l = L[-x+1], r = R[-x+1];
  if (l >= 0) l = -l+1;
  return r-l+1;
}
}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}
inline bool is_prime(long long x) {
  if(x == 1) return false;
  if(x == 2 || x == 3) return true;
  if(x%6 != 1 && x%6 != 5) return false;
  for(long long i = 5; i*i <= x; i += 6)
    if(x%i == 0 || x%(i+2) == 0) return false;
  return true;
}
inline bool MillerRabin(ll x) {
  static const ll test_time = 10;
  if (x < 3) return x == 2;
  ll a = x-1, b = 0;
  while (!(a&1)) a >>= 1, ++b;
  for (ll i = 1, j, v; i <= test_time; ++i) {
    v = (qpow(rnd()%(x-2)+2, a, x));
    if (v == 1 || v == x-1) continue;
    for (j = 0; j < b && v != x-1; ++j) v = v*v%x;
    if (j >= b) return false;
  }
  return true;
}

bool check(int l, int r) {
  ll s = (l+r)*(r-l+1ll)/2;
  // return s > 1 ? MillerRabin(s) : 0;
  return s > 1 ? is_prime(s) : 0;
}

inline void solve() {
  // int x;
  // cin >> x;
  for (int v = 1e3, x = -v; x <= v; ++x) {
  int res = -1, rl, rr;
  for (int len = 1; res == -1; ++len) {
    for (int l = x-len+1, r; l <= x; ++l) {
      r = l+len-1;
      if (check(l, r)) {
        rl = l;
        rr = r;
        res = len;
        break;
      }
    }
  }
  // mx = max(mx, res);
  int tmp = STD::solve(x);
  cout << x << ' ' << tmp <<' ' << res << '\n';
  if (tmp != res) {
    cout << rl << ' ' << rr << '\n';
    return;
  }
  // cout << res << ' ' << mx << '\n';
  }
  // cout << mx << '\n';
  cout << "all ok\n";
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  STD::init();
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}