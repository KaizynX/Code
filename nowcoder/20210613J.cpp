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

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
	long long res = 1, x = a;
	for (H i = p; i; i >>= 1, x = x*x%mo)
		if (i&1) res = res*x%mo;
	return static_cast<T>(res);
}

int n, m, L;
int p[N];

inline void solve() {
	cin >> n >> m >> L;
	ll res = 0;
	for (int i = L+1, k, x; i <= L+n; ++i) {
		k = 0;
		x = i;
		while (x%p[i] == 0) x /= p[i], ++k;
		// cout << x*qpow(p[i], k/m) << '\n';
		res += i-x*qpow(p[i], k/m);
	}
	cout << res << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
	p[1] = 2;
	for (int i = 2; i < N; ++i) {
		for (int j = i; j < N; j += i) {
			if (!p[j]) p[j] = i;
		}
	}
	int T = 1;
	// cin >> T; // scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		solve();
	}
	return 0;
}