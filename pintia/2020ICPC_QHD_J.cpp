/*
 * @Author: Kaizyn
 * @Date: 2020-10-19 18:40:00
 * @LastEditTime: 2020-10-19 20:00:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef pair<int, int> pii;
typedef pair<unsigned, unsigned> puu;
typedef unsigned long long ull;
const int MOD = 998244353;
const int N = 3e5+7;

struct StringHash {
  static const unsigned P1 = 31;
  static const unsigned P2 = 29;
  unsigned ha1[N], ha2[N], pw1[N], pw2[N];
  StringHash() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
      pw1[i] = pw1[i-1]*P1;
      pw2[i] = pw2[i-1]*P2;
    }
  }
  void init(char *s, int len) {
    for (int i = 0; i < len; ++i) {
      ha1[i+1] = ha1[i]*P1+s[i]-'a'+1;
      ha2[i+1] = ha2[i]*P2+s[i]-'a'+1;
    }
  }
  puu get(int l, int r) {
    return {ha1[r]-ha1[l-1]*pw1[r-l+1],
            ha2[r]-ha2[l-1]*pw2[r-l+1]};
  }
};
int n;
long long ans, cur;
puu hst;
int fac[N], inv[N];
char s[N];
StringHash str_hash;
map<puu, int> cnt, vis;

inline void init() {
  fac[0] = fac[1] = 1;
  inv[0] = inv[1] = 1;
  for(int i = 2; i < N; ++i) {
    inv[i] = 1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
    fac[i] = 1ll*fac[i-1]*i%MOD;
  }
  for (int i = 1; i < N; ++i)
    inv[i] = 1ll*inv[i]*inv[i-1]%MOD;
}

inline void update(int l, int r, int k) {
  puu val = str_hash.get(l, r);
  int &t = cnt[val];
  (cur *= fac[t]) %= MOD;
  t += k;
  (cur *= inv[t]) %= MOD;
  hst.first  += k*val.first;
  hst.second += k*val.second;
}


inline int solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  str_hash.init(s+1, n);
  ans = 0;
  for (int d = 1; d <= n; ++d) {
    hst = {0, 0};
    vis.clear();
    cur = fac[n/d];
    cnt.clear();
    for (int i = 1; i+d-1 <= n; i += d) update(i, i+d-1, 1);
    ans += cur;
    vis[hst] = 1;
    if (n%d) for (int y = n%d, i = n-y-d+1; i >= 1; i -= d) {
      update(i, i+d-1, -1);
      update(i+y, i+y+d-1, 1);
      if (++vis[hst] == 1) ans += cur;
    }
    ans %= MOD;
  }
  return ans;
}

signed main() {
  init();
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("Case #%d: %d\n", t, solve());
  }
  return 0;
}