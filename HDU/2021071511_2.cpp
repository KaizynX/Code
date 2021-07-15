/*
 * @Author: Kaizyn
 * @Date: 2021-07-15 15:01:07
 * @LastEditTime: 2021-07-15 15:21:07
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
const int N = (1<<18)+7;

int n, nb;
int a[N], b[N];
int mna[N], mxa[N], mnb[N], mxb[N];
ll c[N];

void calc(int *mn, int *mx, int *arr) {
  for (int i = 0; i < n; ++i) {
    mn[i] = mx[i] = arr[i];
    for (int k = nb^i, j = k; j; j = (j-1)&k) {
      mn[i] = min(mn[i], arr[j|i]);
      mx[i] = max(mx[i], arr[j|i]);
    }
  }
}

inline void solve() {
  cin >> n;
  for (nb = 1; nb < n; nb <<= 1) {}
  --nb;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  calc(mna, mxa, a);
  calc(mnb, mxb, b);
  for (int i = 0; i < n; ++i) {
    c[i] = max({
        1ll*mna[i]*mnb[i],
        1ll*mna[i]*mxb[i],
        1ll*mxa[i]*mnb[i],
        1ll*mxa[i]*mxb[i]
    });
  }
  for (int i = n-1; i; --i) {
    c[i-1] = max(c[i-1], c[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    #ifdef DEBUG
    cout << c[i] << " \n"[i==n-1];
    #endif
    ans = (ans+c[i])%MOD;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}