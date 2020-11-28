/*
 * @Author: Kaizyn
 * @Date: 2020-10-19 18:40:00
 * @LastEditTime: 2020-10-19 19:56:22
 */
#include <bits/stdc++.h>

// #define DEBUG
// #define SET_HASH

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

struct StringHash {
  static const int M1 = 1e9+7;
  static const int M2 = 998244353;
  static const int P1 = 31;
  static const int P2 = 29;
  int ha1[N], ha2[N], pw1[N], pw2[N];
  StringHash() {
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i < N; ++i) {
      pw1[i] = 1ll*pw1[i-1]*P1%M1;
      pw2[i] = 1ll*pw2[i-1]*P2%M2;
    }
  }
  void init(char *s, int len) {
    for (int i = 0; i < len; ++i) {
      ha1[i+1] = (1ll*ha1[i]*P1+s[i]-'a'+1)%M1;
      ha2[i+1] = (1ll*ha2[i]*P2+s[i]-'a'+1)%M2;
    }
  }
  pair<int, int> get(int l, int r) {
    return {(ha1[r]-1ll*ha1[l-1]*pw1[r-l+1]%M1+M1)%M1,
            (ha2[r]-1ll*ha2[l-1]*pw2[r-l+1]%M2+M2)%M2};
  }
};

int n;
long long ans, cur;
unsigned hst;
int fac[N], inv[N];
char s[N];
StringHash str_hash;
map<pair<int, int>, int> cnt;
#ifdef SET_HASH
set<unsigned> vis;
#endif


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
  pair<int, int> val = str_hash.get(l, r);
  int &t = cnt[val];
  (cur *= fac[t]) %= MOD;
  t += k;
  (cur *= inv[t]) %= MOD;
#ifdef SET_HASH
  hst += k*val;
#endif
}


inline int solve() {
  scanf("%s", s+1);
  n = strlen(s+1);
  str_hash.init(s+1, n);
  ans = 0;
  for (int d = 1; d <= n; ++d) {
#ifdef SET_HASH
    hst = 0;
    vis.clear();
#endif
    cur = fac[n/d];
    cnt.clear();
    for (int i = 1; i+d-1 <= n; i += d) update(i, i+d-1, 1);
    ans += cur;
#ifdef SET_HASH
    vis.insert(hst);
#endif
    if (n%d) for (int y = n%d, i = n-y-d+1; i >= 1; i -= d) {
      update(i, i+d-1, -1);
      update(i+y, i+y+d-1, 1);
#ifdef SET_HASH
      if (!vis.count(hst)) ans += cur;
      vis.insert(hst);
#else
      ans += cur;
#endif
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