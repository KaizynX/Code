/*
 * @Author: Kaizyn
 * @Date: 2021-08-08 20:19:04
 * @LastEditTime: 2021-08-08 20:46:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 5e5+7;

int n;
char s[N];
int sa[N], rk[N<<1], height[N];
template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
  static int oldrk[N<<1], id[N], px[N], cnt[N], m;
  memset(cnt, 0, sizeof(int) * (m = 128));
  for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
  for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
  for (int i = n; i; --i) sa[cnt[rk[i]]--] = i;
  for (int w = 1, p, i; w <= n; w <<= 1, m = p) {
    for (p = 0, i = n; i > n - w; --i) id[++p] = i;
    for (i = 1; i <= n; ++i) if (sa[i] > w) id[++p] = sa[i] - w;
    memset(cnt + 1, 0, sizeof(int) * m);
    for (i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
    for (i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (i = n; i; --i) sa[cnt[px[i]]--] = id[i];
    swap(oldrk, rk);
    for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  }
  for (int i = 1, k = 0; i <= n; ++i) {
    if (k) --k;
    while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
    height[rk[i]] = k;
  }
#undef cmp
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  static int stk[N], sz;
  scanf("%s", s+1);
  n = strlen(s+1);
  SA(s, n);
  #ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << height[i] << " \n"[i==n];
  #endif
  ll res = (n+1ll)*n/2*(n-1), cur = 0;
  for (int i = 1; i <= n; ++i) {
    while (sz && height[stk[sz]] >= height[i]) {
      cur -= 1ll*(stk[sz]-stk[sz-1])*height[stk[sz]];
      --sz;
    }
    cur += 1ll*(i-stk[sz])*height[i];
    res -= 2*cur;
    stk[++sz] = i;
    #ifdef DEBUG
    printf("i=%d,cur=%lld,res=%lld,stk=", i, cur, res);
    for (int i = 1; i <= sz; ++i) cout << stk[i] << " \n"[i==sz];
    #endif
  }
  printf("%lld\n", res);
  return 0;
}