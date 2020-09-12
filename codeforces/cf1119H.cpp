/*
 * @Author: Kaizyn
 * @Date: 2020-08-31 15:59:13
 * @LastEditTime: 2020-08-31 16:54:18
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int inv2 = 499122177;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;
const int K = 17;

int n, k, x, y, z, len;
int f[1<<K];
map<int, int> g[2];

template <class T> void fwt(T a[], const int x = 1) {
  for (int l = 2; l <= len; l <<= 1)
  for (int i = 0, k = l>>1; i < len; i += l)
  for (int j = 0; j < k; ++j) {
    (a[i+j] += a[i+j+k]) %= MOD;
    a[i+j+k] = (a[i+j]-2*a[i+j+k]%MOD+MOD)%MOD;
    a[i+j] = 1ll*a[i+j]*x%MOD; a[i+j+k] = 1ll*a[i+j+k]*x%MOD;
  }
}

void my_fwt(const vector<pii> &vec) {
  static map<int, int> g[2];
  g[0].clear();
  for (const pii &pr : vec) g[0][pr.first] += pr.second;
  for (int i = 0; i < k; ++i) {
    g[~i&1].clear();
    while (g[i&1].size()) {
      int p = g[i&1].begin()->first;
      int v = g[i&1].begin()->second;
      int rp = p^(1<<i), rv = 0;
      g[i&1].erase(g[i&1].find(p));
      if (g[i&1].count(rp)) {
        rv = g[i&1][rp];
        g[i&1].erase(g[i&1].find(rp));
      }
      if (p > rp) swap(p, rp), swap(v, rv);
      (v += rv) %= MOD;
      rv = (v-2*rv%MOD+MOD)%MOD;
      // v = v+rv, rv = v-rv
      g[~i&1][p] = v;
      g[~i&1][rp] = rv;
    }
  }
  for (const pii &pr : g[k&1]) {
    int p = pr.first;
    int v = pr.second;
    f[p] = 1ll*f[p]*v%MOD;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin >> n >> k >> x >> y >> z;
  len = 1<<k;
  f[0] = 1;
  fwt(f);
  vector<pii> vec;
  for (int i = 1, a, b, c; i <= n; ++i) {
    cin >> a >> b >> c;
    vec.clear();
    vec.emplace_back(a, x);
    vec.emplace_back(b, y);
    vec.emplace_back(c, z);
    my_fwt(vec);
  }
  fwt(f, inv2);
  for (int i = 0; i < len; ++i) cout << f[i] << " \n"[i==len-1];
  return 0;
}