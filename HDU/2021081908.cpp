/*
 * @Author: Kaizyn
 * @Date: 2021-08-19 12:06:29
 * @LastEditTime: 2021-08-19 14:23:29
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#ifdef DEBUG
const int N = 10;
using BT = bitset<6>;
#else
const int N = 2e5+3;
using BT = bitset<200'000>;
#endif


struct SAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A];
  int pre[M], suf[M], n;
  BT vis[M];
  // SAM() { init(); }
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    for (int i = 0; i < sz; ++i) vis[i].reset();
    link[0] = -1; sz = 1; last = 0;
  }
  int extend(int c) {
    int cur = sz++, p = last;
    len[cur] = len[last]+1;
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    link[clone] = link[q];
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[q] = link[cur] = clone;
    return cur;
  }
  void build(const char *s, int n) {
    static int t[M], rk[M];
    this->n = n;
    init();
    for (int i = 0; i < n; ++i) {
      vis[last = extend(s[i]-C)].set(i);
      pre[i+1] = last;
    }
    for (int i = n, j = last; i; --i) {
      while (j && len[link[j]] >= i) j = link[j];
      suf[i] = j;
    }
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      vis[j] |= vis[i];
    }
  }
  int query(int l, int r) {
    #ifdef DEBUG
    cout << vis[pre[l]] << ' ' << vis[suf[r]] << '\n';
    #endif
    return (vis[pre[l]]&(vis[suf[r]]>>r)).count();
  }
};

int n, q;
char s[N];
SAM sam;

inline void solve() {
  scanf("%d%d%s", &n, &q, s);
  sam.build(s, n);
  for (int _ = q, l, r; _; --_) {
    scanf("%d%d", &l, &r);
    printf("%d\n", sam.query(l, r));
  }
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