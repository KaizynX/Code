/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 20:46:36
 * @LastEditTime: 2021-07-26 23:51:25
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
  static const int A = 26;
  static const char C = 'a';
  struct State {
    int len, link, nex[A];
    State& operator =(const State &st) {
      len = st.len;
      link = st.link;
      memcpy(nex, st.nex, sizeof(nex));
      return *this;
    }
  } st[N<<1];
  int sz, last;
  int f[N<<1], g[N<<1], c[N<<1], b[N<<1];
  void init() {
    memset(st, 0, sizeof(State)*sz);
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
  }
  void extend(char c) {
    int cur = sz++;
    f[cur] = st[cur].len = st[last].len+1;
    int p = last;
    while (~p && !st[p].nex[c-C]) {
      st[p].nex[c-C] = cur;
      p = st[p].link;
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].nex[c-C];
      if (st[p].len+1 == st[q].len) {
        st[cur].link = q;
      } else {
        int clone = sz++;
        st[clone] = st[q];
        st[clone].len = st[p].len+1;
        f[clone] = st[clone].len;
        while (~p && st[p].nex[c-C] == q) {
          st[p].nex[c-C] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
  void sort() {
    // memset(f, 0x3f, sizeof f);
    for (int i = 0; i < sz; ++i) ++c[st[i].len];
    for (int i = 1; i <= sz; ++i) c[i] += c[i-1];
    for (int i = 0; i < sz; ++i) b[--c[st[i].len]] = i;
  }
  void update(const string &t) {
    int v = 0, l = 0;
    for (char c : t) {
      while (v && !st[v].nex[c-C]) {
        v = st[v].link;
        l = st[v].len;
      }
      if (st[v].nex[c-C]) {
        v = st[v].nex[c-C];
        ++l;
      } else {
        assert(v == 0);
        v = l = 0;
      }
      g[v] = max(g[v], l);
      assert(g[v] <= st[v].len);
    }
    for (int i = sz-1, fa; i >= 0; --i) {
      v = b[i];
      fa = st[v].link;
      if (~fa) g[fa] = max(g[fa], min(st[fa].len, g[v]));
      f[v] = min(f[v], g[v]);
      g[v] = 0;
    }
  }
  int query() {
    return *max_element(f, f+sz);
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