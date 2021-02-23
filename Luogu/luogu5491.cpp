/*
 * @Author: Kaizyn
 * @Date: 2021-02-19 16:23:51
 * @LastEditTime: 2021-02-19 17:02:57
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
// const int N = ;

namespace Cipolla {

int mod;
long long I_mul_I; // 虚数单位的平方

struct complex {
  long long real, imag;
  complex(long long real = 0, long long imag = 0): real(real), imag(imag) { }
};
inline bool operator == (complex x, complex y) {
  return x.real == y.real and x.imag == y.imag;
}
inline complex operator * (complex x, complex y) {
  return complex((x.real * y.real + I_mul_I * x.imag % mod * y.imag) % mod,
      (x.imag * y.real + x.real * y.imag) % mod);
}

complex power(complex x, int k) {
  complex res = 1;
  while(k) {
    if(k & 1) res = res * x;
    x = x * x;
    k >>= 1;
  }
  return res;
}

bool check_if_residue(int x) {
  return power(x, (mod - 1) >> 1) == 1;
}

void solve(int n, int p, int &x0, int &x1) {
  mod = p;
  if (power(n, p>>1) == p-1) return x0 = -1, void();
  if (power(n, p>>1) == 0) return x0 = x1 = 0, void();

  long long a = rand() % mod;
  while(!a or check_if_residue((a * a + mod - n) % mod))
    a = rand() % mod;
  I_mul_I = (a * a + mod - n) % mod;

  x0 = int(power(complex(a, 1), (mod + 1) >> 1).real);
  x1 = mod - x0;
}
} // namespace Cipolla

inline void solve() {
  int n, p, x0, x1;
  cin >> n >> p;
  Cipolla::solve(n, p, x0, x1);
  if (x0 == -1) return cout << "Hola!\n", void();
  if (x0 > x1) swap(x0, x1);
  if (x0 == x1) cout << x0 << '\n';
  else cout << x0 << ' ' << x1 << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}