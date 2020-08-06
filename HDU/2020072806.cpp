/*
 * @Author: Kaizyn
 * @Date: 2020-07-28 12:55:24
 * @LastEditTime: 2020-07-28 16:52:11
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e2+7;

struct Combination {
  int fac[N], inv[N];
  void init(const int &n) {
    fac[0] = inv[0] = fac[1] = inv[1] = 1;
    for (int i = 2; i <= n; ++i) {
      fac[i] = 1ll*fac[i-1]*i%MOD;
      inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    }
    for (int i = 2; i <= n; ++i) {
      inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
    }
  }
  int A(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[p-q]%MOD : 0;
  }
  int C(const int &p, const int &q) {
    return p >= q ? 1ll*fac[p]*inv[q]%MOD*inv[p-q]%MOD : 0;
  }
};

int d;
int cnt[10], dig[N];
long long l, r;
long long pw10[N];
Combination comb;
vector<int> bc[10];

inline void init() {
  pw10[0] = 1;
  for (int i = 1; i <= 18; ++i) pw10[i] = pw10[i-1]*10;
  for (int i = 0; i < 1<<9; ++i) {
    bc[__builtin_popcount(i)].emplace_back(i);
  }
}

long long calc(long long x) {
  string s = to_string(x);
  int n = s.size();
  long long res = x;
  for (int i = 0; i < n; ++i) {
    dig[i] = s[i]-'0';
    // 第i位填j
    for (int j = !i; j < dig[i]; ++j) {
      ++cnt[j];
      // 剩下有nd个d
      for (int nd = 0; nd < n-i-1; ++nd) {
        cnt[d] += nd;
        int rest = n-i-1-nd;
        for (int bit = 1; bit < 1<<9; ++bit) {
          int need = 0;
          for (int k = 0; k <= 9; ++k) if (k != d) {
            need += max(0, cnt[d]-cnt[k]);
          }
          if (need > rest) continue;
          res -= comb.C(rest-need+8, 8);
        }
        cnt[d] -= nd;
      }
    }
    ++cnt[dig[i]];
  }
  for (int i = 0; i < n; ++i) {
    ;
  }
  return res;
}

inline void solve() {
  cin >> l >> r >> d;
  cout << calc(r)-calc(l-1) << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  init();
  comb.init(30);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}