/*
 * @Author: Kaizyn
 * @Date: 2021-07-26 22:19:54
 * @LastEditTime: 2021-07-26 22:55:13
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

struct SAM {
  int last, sz, link[N<<1], len[N<<1], nex[N<<1][26];
  int c[N<<1], b[N<<1], mx[N<<1], mi[N<<1];
  void init() { last = sz = 1; }
  void extend(char ch) {
    int c = ch-'a', p = last, np;
    link[last = np = ++sz] = 1;
    mi[sz] = len[sz] = len[p]+1;
    for ( ; p && !nex[p][c]; p = link[p]) nex[p][c] = np;
    if (!p) return;
    int q = nex[p][c], nq;
    if (len[p]+1 == len[q]) return link[np] = q, void();
    link[nq = ++sz] = link[q];
    len[sz] = len[p]+1;
    memcpy(nex[nq], nex[q], sizeof nex[q]);
    for (link[q] = link[np] = nq; nex[p][c] == q; p = link[p]) nex[p][c] = nq;
  }
  void sort() {
    memset(mi, 0x3f, sizeof mi);
    for (int i = 1; i <= sz; ++i) ++c[len[i]];
    for (int i = 1; i <= sz; ++i) c[i] += c[i-1];
    for (int i = 1; i <= sz; ++i) b[c[len[i]]--] = i;
  }
  void update(const string &t) {
    int l = 0, v = 1, c;
    for (char ch : t) {
      c = ch-'a';
      while (v && !nex[v][c]) v = link[v], l = len[v];
      if (v) {
        v = nex[v][c];
        mx[v] = max(mx[v], ++l);
      } else {
        v = 1;
        l = 0;
      }
    }
    for (int i = sz, fa; i; --i) {
      v = b[i];
      fa = link[v];
      mx[fa] = max(mx[fa], min(mx[v], len[fa]));
      mi[v] = min(mi[v], mx[v]);
      mx[v] = 0;
    }
  }
  int query() {
    return *max_element(mi+1, mi+sz+1);
  }
};

string s;
SAM sam;

inline void solve() {
  sam.init();
  cin >> s;
  for (char c : s) sam.extend(c);
  sam.sort();
  while (cin >> s) sam.update(s);
  cout << sam.query() << '\n';
}


signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}