/*
 * @Author: Kaizyn
 * @Date: 2021-07-15 14:49:18
 * @LastEditTime: 2021-07-15 15:47:05
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

namespace FWT {
#define forforfor for (int l = 2; l <= len; l <<= 1)\
                  for (int i = 0, k = l>>1; i < len; i += l)\
                  for (int j = 0; j < k; ++j)

  const int SIZE = (1<<18)+3;
  int len;
  // int f[SIZE], g[SIZE];
  /*
  template <class T> void init(T a[], const int &n, T b[], const int &m) {
    len = 1;
    while (len < max(n, m)) len <<= 1;
    for (int i = 0; i < n; ++i) f[i] = a[i];
    for (int i = n; i < len; ++i) f[i] = 0;
    for (int i = 0; i < m; ++i) g[i] = b[i];
    for (int i = m; i < len; ++i) g[i] = 0;
  }
  template <class T> void fwt_or(T a[]) {
    // forforfor a[i+j+k] = (a[i+j+k]+1ll*a[i+j]*x)%MOD;
    forforfor a[i+j+k] = max(a[i+j+k], a[i+j]);
  }
  template <class T> void fwt_and(T a[]) {
    // forforfor a[i+j] = (a[i+j]+1ll*a[i+j+k]*x)%MOD;
    forforfor a[i+j] = max(a[i+j], a[i+j+k]);
  }
  */
  template <class T> void fwt_and_max(T a[]) {
    forforfor if (i+j+k < n) a[i+j] = max(a[i+j], a[i+j+k]);
  }
  template <class T> void fwt_and_min(T a[]) {
    forforfor if (i+j+k < n) a[i+j] = min(a[i+j], a[i+j+k]);
  }
  /*
  template <class T> void work_and(const T a[], const int &n, const T b[], const int &m) {
    init(a, n, b, m); fwt_and(f); fwt_and(g);
    // for (int i = 0; i < len; ++i) f[i] = 1ll*f[i]*g[i]%MOD;
    // fwt_and(f, MOD-1); // fwt_and(x, -1)
  }
  */
  template <class T> void work_and(T mn[], T mx[], const T a[], const int &n) {
    len = 1;
    while (len < n) len <<= 1;
    for (int i = 0; i < n; ++i) mn[i] = mx[i] = a[i];
    for (int i = n; i < len; ++i) mn[i] = mx[i] = 0;
    fwt_and_max(mx);
    fwt_and_min(mn);
  }
#undef forforfor
} // namespace FWT


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
  FWT::work_and(mna, mxa, a, n);
  FWT::work_and(mnb, mxb, b, n);
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
  cout << (ans+MOD)%MOD << '\n';
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