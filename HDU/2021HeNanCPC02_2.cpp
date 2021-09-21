/*
 * @Author: Kaizyn
 * @Date: 2021-09-21 15:18:31
 * @LastEditTime: 2021-09-21 16:34:03
 */
#include <bits/stdc++.h>
#define DEBUG
using namespace std;
const int MOD = 998244353;
const int N = 1e6+7;

int k;
char s[N];
int nex[N];

inline void get_next(const char *s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; s[i]; ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%d", s, &k);
    get_next(s, nex);
    long long ans = 1;
    for (int i = 1, j, d, f; s[i-1]; ++i) {
      j = nex[i];
      if (j+j <= i) {
        f = i%k == 0;
      } else {
        d = i-j;
        if ((i/d)&1) {
          // f = (i/d/(k/__gcd(d, k))+1)/2;
          f = 0;
          for (j = i; j+j > i; j = nex[j]) f += (j+j-i)%k == 0;
        }
        else f = i/(2*d)/(k/__gcd(2*d, k));
      }
      #ifdef DEBUG
      cout << f << ' ';
      #endif
      ans = ans*(f+1)%MOD;
    }
    printf("%lld\n", ans);
  }
  return 0;
}