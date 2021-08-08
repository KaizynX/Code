/*
 * @Author: Kaizyn
 * @Date: 2021-08-08 20:57:38
 * @LastEditTime: 2021-08-08 21:09:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e5+7;

struct generalSAM {
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, len[M], link[M], nex[M][A], cnt[M];
  generalSAM() { init(); }
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    memset(cnt, 0, sizeof(int)*sz);
    link[0] = -1; sz = 1;
  }
  int extend(int last, int c) {
    if (nex[last][c]) {
      int p = last, cur = nex[p][c];
      if (len[p]+1 == len[cur]) return cur;
      int q = sz++;
      len[q] = len[p]+1;
      memcpy(nex[q], nex[cur], sizeof nex[q]);
      for ( ; ~p && nex[p][c] == cur; p = link[p]) nex[p][c] = q;
      link[q] = link[cur];
      link[cur] = q;
      return q;
    }
    int cur = sz++, p = last;
    len[cur] = len[p]+1;
    for ( ; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    len[clone] = len[p]+1;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[clone] = link[q];
    link[q] = link[cur] = clone;
    return cur;
  }
  void insert(const string &s) {
    int last = 0; for (char ch : s) ++cnt[last = extend(last, ch-C)];
  }
  int solve(int n, int k) {
    static int t[M], rk[M], add[N];
    memset(t, 0, sizeof(int)*sz);
    memset(add+1, 0, sizeof(int)*(n+1));
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      cnt[j] += cnt[i];
      if (cnt[i] == k) ++add[len[i]], --add[len[j]];
    }
    int res = -1;
    for (int i = n; i; --i) {
      add[i] += add[i+1];
      if (!add[i]) continue;
      if (res == -1 || add[i] > add[res]) res = i;
    }
    return res;
  }
};

int k;
string s;
generalSAM sam;

inline void solve() {
  cin >> s >> k;
  sam.init();
  sam.insert(s);
  cout << sam.solve(s.size(), k) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}