/*
 * @Author: Kaizyn
 * @Date: 2022-03-19 20:05:34
 * @LastEditTime: 2022-03-19 20:24:01
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 6e5 + 7;

template <typename T, typename H>
inline T qpow(const T &a, const H &p, const int &mo = MOD) {
  long long res = 1, x = a;
  for (H i = p; i; i >>= 1, x = x*x%mo)
    if (i&1) res = res*x%mo;
  return static_cast<T>(res);
}

namespace NTT { // array [0, n)
const int SIZE = (1<<21)+3;
const int G = 3;
int len, bit;
int rev[SIZE];
long long f[SIZE], g[SIZE];
template <class T>
void ntt(T a[], int flag = 1) {
  for (int i = 0; i < len; ++i)
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  for (int base = 1; base < len; base <<= 1) {
    long long wn = qpow(G, (MOD-1)/(base*2)), w;
    if (flag == -1) wn = qpow(wn, MOD-2);
    for (int i = 0; i < len; i += base*2) {
      w = 1;
      for (int j = 0; j < base; ++j) {
        long long x = a[i+j], y = w*a[i+j+base]%MOD;
        a[i+j] = (x+y)%MOD;
        a[i+j+base] = (x-y+MOD)%MOD;
        w = w*wn%MOD;
      }
    }
  }
}
template <class T>
void work(T a[], const int &n, T b[], const int &m) {
  len = 1; bit = 0;
  while (len < n+m) len <<= 1, ++bit;
  for (int i = 0; i < n; ++i) f[i] = a[i];
  for (int i = n; i < len; ++i) f[i] = 0;
  for (int i = 0; i < m; ++i) g[i] = b[i];
  for (int i = m; i < len; ++i) g[i] = 0;
  for (int i = 0; i < len; ++i)
    rev[i] = (rev[i>>1]>>1)|((i&1)<<(bit-1));
  ntt(f, 1); ntt(g, 1);
  for (int i = 0; i < len; ++i) f[i] = f[i]*g[i]%MOD;
  ntt(f, -1);
  long long inv = qpow(len, MOD-2);
  for (int i = 0; i < n+m-1; ++i) f[i] = f[i]*inv%MOD;
}
} // namespace NTT

int n;
int a[N], s[N];
int f[N], g[N];

inline void solve() {
  int cnt = 0, ans = 0;
  cin >> n;
  s[0] = n;
  f[n] = g[n] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    cnt += a[i];
    s[i] = s[i - 1];
    if (a[i]) --s[i];
    else ++s[i];
    f[s[i]] = 1;
    g[2 * n - s[i]] = 1;
  }
  NTT::work(f, 2 * n + 1, g, 2 * n + 1);
  auto *ff = NTT::f;
  #ifdef DEBUG
  orzarr(s + 1, n);
  orzarr(ff, 4 * n + 2);
  #endif
  for (int i = 0; i < 4 * n + 2; ++i) {
    if (ff[i] == 0) continue;
    int real = cnt + (i - 2 * n);
    if (real >= 0 && real <= n) ++ans;
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}