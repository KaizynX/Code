/*
 * @Author: Kaizyn
 * @Date: 2020-07-12 13:37:12
 * @LastEditTime: 2020-07-12 15:50:46
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

int n;
char str[N];
int a[N], nex[N][2], res[N];
int sa[N], rk[N<<1];

template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
#define cmp(x, y, w) oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w]
  static int oldrk[N<<1], id[N], px[N], cnt[N], m;
  memset(cnt, 0, sizeof(int) * (m = 128));
  // memset(rk + 1, 0, sizeof(int) * n);
  for (int i = 1; i <= n; ++i) ++cnt[rk[i] = s[i]];
  for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
  for (int i = n; i; --i) sa[cnt[rk[i]]--] = i;
  for (int w = 1, p, i; w <= n; w <<= 1, m = p) {
    for (p = 0, i = n; i > n - w; --i) id[++p] = i;
    for (int i = 1; i <= n; ++i)
      if (sa[i] > w)
        id[++p] = sa[i] - w;
    memset(cnt + 1, 0, sizeof(int) * m);
    for (int i = 1; i <= n; ++i) ++cnt[px[i] = rk[id[i]]];
    for (int i = 1; i <= m; ++i) cnt[i] += cnt[i - 1];
    for (int i = n; i; --i) sa[cnt[px[i]]--] = id[i];
    memcpy(oldrk + 1, rk + 1, sizeof(int) * 2 * n);
    for (p = 0, i = 1; i <= n; ++i) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
  }
#undef cmp
}

/*
inline bool cmp(const int &x, const int &y) {
  // 最后一个最小
  if (x == n) return true;
  if (y == n) return false;
  if ((str[x] == str[x+1]) != (str[y] == str[y+1])) {
    // 前两个不相等则小
    return str[x] != str[x+1];
  }
  if (str[x] != str[x+1]) {
    // ab***
    return rk[x+2] < rk[y+2];
  } else {
    // aaaaaab**
    int nx = nex[x][(str[x]-'a')^1], ny = nex[y][(str[y]-'a')^1];
    if (nx-x != ny-y) return nx-x < ny-y;
    return rk[nx+1] < rk[ny+1];
  }
}
*/

inline bool cmp(const int &x, const int &y) {
  if (x == n) return true;
  if (y == n) return false;
  int nx = nex[x][(str[x]-'a')^1], ny = nex[y][(str[y]-'a')^1];
  if (nx-x != ny-y) return nx-x < ny-y;
  return rk[nx+1] < rk[ny+1];
}

inline void solve() {
  scanf("%s", str+1);
  int pre[2] = {0, 0};
  for (int i = 1, c; i <= n; ++i) {
    res[i] = i;
    c = str[i]-'a';
    a[i] = pre[c] ? i-pre[c] : 0;
    ++a[i];
    pre[c] = i;
  }
  SA(a, n);
  rk[n+1] = rk[n+2] = 0;
  nex[n+1][0] = nex[n+1][1] = n+1;
  for (int i = n, c; i; --i) {
    c = str[i]-'a';
    nex[i][c^1] = nex[i+1][c^1];
    nex[i][c] = i;
  }
  #ifdef DEBUG
  cout << "a: "; for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
  cout << "sa:"; for (int i = 1; i <= n; ++i) cout << sa[i] << " \n"[i==n];
  cout << "rk:"; for (int i = 1; i <= n; ++i) cout << rk[i] << " \n"[i==n];
  #endif
  sort(res+1, res+n+1, cmp);
  for (int i = 1; i <= n; ++i) {
    printf("%d%c", res[i], " \n"[i==n]);
  }
}

signed main() {
  // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (scanf("%d", &n) == 1) solve();
  return 0;
}