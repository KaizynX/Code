/*
 * @Author: Kaizyn
 * @Date: 2021-06-13 14:16:56
 * @LastEditTime: 2021-06-13 14:21:48
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

int check[N], mp[N], p[N], tot;

struct Euler {
  void init(int n) {
    tot = 0;
    mp[1] = 2;
    for (int i = 2; i <= n; ++i) check[i] = 1;
    for (int i = 2; i <= n; ++i) {
      if (check[i]) p[++tot] = i, mp[i] = i;
      for (int j = 1; j <= tot; ++j) {
        if (i*p[j] > n) break;
        check[i*p[j]] = false;
        mp[i*p[j]] = p[j];
        if (i%p[j] == 0) break;
      }
    }
  }
} E;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
	long long res = 1, x = a;
	for (H i = p; i; i >>= 1, x = x*x%mo)
		if (i&1) res = res*x%mo;
	return static_cast<T>(res);
}

int n, m, L;

inline void solve() {
	cin >> n >> m >> L;
	ll res = 0;
	for (int i = L+1, k, x; i <= L+n; ++i) {
		k = 0;
		x = i;
		while (x%mp[i] == 0) x /= mp[i], ++k;
		// cout << x*qpow(p[i], k/m) << '\n';
		res += i-x*qpow(mp[i], k/m);
	}
	cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  E.init(2e7);
	int T = 1;
	// cin >> T; // scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
	return 0;
}