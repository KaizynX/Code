/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 14:35:26
 * @LastEditTime: 2020-05-31 14:39:32
 */ 
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

char s[N];
int sa[N], rk[N<<1], height[N];

template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
    static int oldrk[N<<1];
    memset(rk+n+1, 0, sizeof(int)*n);
    for (int i = 1; i <= n; ++i) rk[i] = s[i];
    for (int w = 1; w <= n; w <<= 1) {
        iota(sa+1, sa+n+1, 1);
        sort(sa+1, sa+n+1, [&](const int &x, const int &y) {
          return rk[x] == rk[y] ? rk[x+w] < rk[y+w] : rk[x] < rk[y];
        });
        memcpy(oldrk+1, rk+1, sizeof(int)*2*n);
        for (int p = 0, i = 1; i <= n; ++i) {
            if (oldrk[sa[i]] == oldrk[sa[i-1]] &&
                oldrk[sa[i]+w] == oldrk[sa[i-1]+w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }
    }
    for (int i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
        height[rk[i]] = k;
    }
}

inline void solve() {
  scanf("%s", s+1);
  int n = strlen(s+1);
  SA(s, n);
  #ifdef DEBUG
  for (int i = 0; i <= n; ++i) cout << sa[i] << " \n"[i==n];
  for (int i = 0; i <= n; ++i) cout << rk[i] << " \n"[i==n];
  for (int i = 0; i <= n; ++i) cout << height[i] << " \n"[i==n];
  #endif
  cout << max(height[rk[1]], height[rk[1]+1]) << endl;
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}