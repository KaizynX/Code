/*
 * @Author: Kaizyn
 * @Date: 2020-08-20 11:56:28
 * @LastEditTime: 2020-08-20 16:57:06
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e6+7;
const int M = 15e6+7;
const int SHIT = 10;

struct Node {
  ull a, b;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    ull m1 = lhs.a*rhs.b, m2 = rhs.a*lhs.b;
    return m1 == m2 ? lhs.b < rhs.b : m1 > m2;
  }
};

int n, m;
ull f[N*3];
Node c[N*2];
constexpr int threshold = 10000000;
unsigned long long k1,k2;
unsigned long long xorShift128Plus(){
    unsigned long long k3 = k1,k4 = k2;
    k1 = k4;
    k3 ^= (k3<<23);
    k2 = k3^k4^(k3>>17)^(k4>>26);
    return k2 +k4;
}
void gen(int n,unsigned long long _k1,unsigned long long _k2){
    k1 = _k1, k2 = _k2;
    for (int i = 1; i <= n; i++){
        c[i].a = xorShift128Plus() % threshold + 1;
        c[i].b = xorShift128Plus() % threshold + 1;
    }
}

inline void solve() {
  gen(n, k1, k2);
  for (int i = 1; i <= n; ++i) {
    ull a = c[i].a, b = c[i].b;
    if (a < b) {
      c[i] = {a+b, 2};
      c[i+n] = {a, 1};
    } else {
      c[i] = {a, 1};
      c[i+n] = {b+a, 2};
    }
    // init
    f[i] = f[i+n] = f[i+n+n] = 0;
  }
  sort(c+1, c+n*2+1);
  for (int i = 1, tot = 0; i <= 2*n; ++i) {
    for (int j = tot; j >= max(tot-SHIT, 0); --j) {
      f[j+c[i].b] = max(f[j+c[i].b], f[j]+c[i].a);
    }
    tot += c[i].b;
  }
#ifdef DEBUG
  // cout << "a:"; for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  // cout << "b:"; for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i==n];
  cout << "f:"; for (int i = 1; i <= 3*n; ++i) cout << f[i] << " \n"[i==3*n];
  cout.flush();
#endif
  ull res = 0;
  for (int i = 1; i <= m; ++i) res ^= f[min(i, 3*n)];
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n >> m >> k1 >> k2) solve();
  return 0;
}