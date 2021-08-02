/*
 * @Author: Kaizyn
 * @Date: 2021-08-02 13:46:11
 * @LastEditTime: 2021-08-02 14:41:23
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
template <typename T>
T inverse(T a, T m = MOD) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  if (u < 0) u += MOD;
  return u;
}
namespace FWT {
#define forforfor for (int l = 2; l <= len; l <<= 1)\
                  for (int i = 0, k = l>>1; i < len; i += l)\
                  for (int j = 0; j < k; ++j)

  const int SIZE = (1<<17)+3;
  int len;
  int f[SIZE], g[SIZE];
  template <class T> void init(T a[], const int &n, T b[], const int &m) {
    len = 1;
    while (len < max(n, m)) len <<= 1;
    for (int i = 0; i < n; ++i) f[i] = a[i];
    for (int i = n; i < len; ++i) f[i] = 0;
    for (int i = 0; i < m; ++i) g[i] = b[i];
    for (int i = m; i < len; ++i) g[i] = 0;
  }
  template <class T> void fwt_xor(T a[], const int x = 1) {
    forforfor {
      (a[i+j] += a[i+j+k]) %= MOD;
      a[i+j+k] = (a[i+j]-2*a[i+j+k]%MOD+MOD)%MOD;
      a[i+j] = 1ll*a[i+j]*x%MOD; a[i+j+k] = 1ll*a[i+j+k]*x%MOD;
    }
  }
  template <class T> void work_xor(const T a[], const int &n, const T b[], const int &m) {
    init(a, n, b, m); fwt_xor(f); fwt_xor(g);
    for (int i = 0; i < len; ++i) f[i] = 1ll*f[i]*g[i]%MOD;
    fwt_xor(f, inverse(2)); // fwt_xor(x, 1/2)
    #ifdef DEBUG
    cout << "FWT:***********\n";
    cout << "a:";for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i==n-1];
    cout << "b:";for (int i = 0; i < m; ++i) cout << b[i] << " \n"[i==m-1];
    cout << "f:";for (int i = 0; i < len; ++i) cout << f[i] << " \n"[i==len-1];
    #endif
  }
#undef forforfor
} // namespace FWT

const int N = (1<<17)+3;

int n;
int a[N], f[N], ones[N], k[N];

void cdq_fwt(int l, int r) {
  if (r-l <= 1) {
    if (l == 0) return;
    #ifdef DEBUG
    printf("i=%d,k=%d,f=%d,",l,k[l],f[l]);
    #endif
    // f[l] = (f[l]+1ll)*inverse((1-k[l]+MOD)%MOD)%MOD;
    f[l] = (f[l]+1ll)*inverse(k[l])%MOD;
    #ifdef DEBUG
    printf("f'=%d\n",f[l]);
    #endif
    return;
  }
  int mid = (l+r)>>1;
  cdq_fwt(l, mid);
  // NTT::work(f+l, mid-l, g, r-l);
  // FWT::work_xor(f+l, mid-l, a+mid, r-mid);
  // for (int i = mid; i < r; ++i) (f[i] += FWT::f[i-mid]) %= MOD;
  FWT::work_xor(f+l, mid-l, a, r-l);
  for (int i = mid; i < r; ++i) (f[i] += FWT::f[i-l]) %= MOD;
  // FWT::work_xor(ones, mid-l, a+mid, r-mid);
  // for (int i = mid; i < r; ++i) (k[i] += FWT::f[i-mid]) %= MOD;
  FWT::work_xor(ones, mid-l, a, r-l);
  for (int i = mid; i < r; ++i) (k[i] += FWT::f[i-l]) %= MOD;
  cdq_fwt(mid, r);
}

inline void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
    k[i] = 0;
    f[i] = 0;
  }
  sum = inverse(sum, MOD);
  for (int i = 0; i < n; ++i) {
    a[i] = 1ll*a[i]*sum%MOD;
    #ifdef DEBUG
    cout << a[i] << " \n"[i==n-1];
    #endif
  }
  cdq_fwt(0, n);
  #ifdef DEBUG
  cout << "k:";for (int i = 0; i < n; ++i) cout << k[i] << " \n"[i==n-1];
  cout << "f:";for (int i = 0; i < n; ++i) cout << f[i] << " \n"[i==n-1];
  #endif
  cout << f[n-1] << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  fill(ones, ones+N, 1);
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}