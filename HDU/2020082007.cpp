/*
 * @Author: Kaizyn
 * @Date: 2020-08-20 11:56:28
 * @LastEditTime: 2020-08-20 16:37:23
 */
#include <bits/stdc++.h>

#define DEBUG

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
  ull v;
  int t, id;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    ull m1 = lhs.v*rhs.t, m2 = rhs.v*lhs.t;
    return m1 == m2 ? lhs.t < rhs.t : m1 > m2;
  }
};

int n, m;
int last[N], tot[N*3];
ull a[N], b[N], f[N*3];
Node c[N*3];
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
        a[i] = xorShift128Plus() % threshold + 1;
        b[i] = xorShift128Plus() % threshold + 1;
    }
}

inline void solve() {
  gen(n, k1, k2);
  for (int i = 1; i <= n; ++i) {
    c[i] = {a[i], 1, i};
    c[i+n] = {a[i]+b[i], 2, i};
    c[i+n+n] = {a[i]+b[i]+a[i], 3, i};
    // init
    last[i] = 0;
    f[i] = f[i+n] = f[i+n+n] = 0;
  }
  sort(c+1, c+n*3+1);
  for (int i = 1, l; i <= 3*n; ++i) {
    tot[i] = tot[i-1];
    l = last[c[i].id];
    for (int j = max(i-SHIT, 0); j < tot[l]; ++j) {
      f[j+c[i].t] = max(f[j+c[i].t], f[j]+c[i].v);
    }
    if (c[i].t > c[l].t) {
      for (int j = max(i-SHIT, tot[l]); j <= tot[i]; ++j) {
        f[j+c[i].t-c[l].t] = max(f[j+c[i].t-c[l].t], f[j]+c[i].v-c[l].v);
      }
      tot[i] += c[i].t-c[l].t;
      last[c[i].id] = i;
    }
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