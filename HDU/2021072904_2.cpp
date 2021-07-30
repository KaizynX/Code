/*
 * @Author: Kaizyn
 * @Date: 2021-07-29 14:21:44
 * @LastEditTime: 2021-07-29 15:30:04
 */
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int N = 1e5+7;

int n;
ll k;
char str[N];
int cost[26], sum[N];
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
    for (int i = 1; i <= n; ++i)
      if (sa[i] > w) id[++p] = sa[i] - w;
    memset(cnt + 1, 0, sizeof(int) * m);
    for (int i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i; --i) sa[cnt[px[i]]--] = id[i];
    memcpy(oldrk + 1, rk + 1, sizeof(int) * 2 * n);
    for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  }
  for (int i = 1, k = 0; i <= n; ++i) {
    if (k) --k;
    while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
    height[rk[i]] = k;
  }
#undef cmp
}

ll check(int val) { // <= val 子串数量
  ll cnt = 0;
  for (int i = 1, j, k; i <= n; ++i) {
    j = sa[i]+height[i];
    k = upper_bound(sum+j, sum+n+1, val+sum[sa[i]-1])-sum;
    cnt += k-j;
  }
  return cnt;
}

inline void solve() {
  scanf("%d%lld%s", &n, &k, str+1);
  for (int i = 0; i < 26; ++i) scanf("%d", cost+i);
  ll all = n*(n+1ll)/2;
  SA(str, n);
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i-1]+cost[str[i]-'a'];
    all -= height[i];
  }
  #ifdef DEBUG
  cout <<  "all:" << all << '\n';
  for (int i = 1; i <= n; ++i) cout << sum[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << sa[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << height[i] << " \n"[i==n];
  for (int i = 1; i <= sum[n]; ++i) {
    cout << check(i) << " \n"[i==sum[n]];
  }
  #endif
  if (all < k) return puts("-1"), void();
  int l = 1, r = sum[n], mid;
  while (l < r) {
    mid = (l+r)/2;
    if (check(mid) >= k) r = mid;
    else l = mid+1;
  }
  printf("%d\n", l);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}