/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 17:22:20
 * @LastEditTime: 2021-07-25 17:26:04
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
const int N = 2.5e5+7;

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
  void init() {
    memset(st, 0, sizeof(State)*sz);
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
  }
  void extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len+1;
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
        while (~p && st[p].nex[c-C] == q) {
          st[p].nex[c-C] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
  int lcs(const string &t) {
    int v = 0, l = 0, mx = 0;
    for (char c : t) {
      while (v && !st[v].nex[c-C]) {
        v = st[v].link;
        l = st[v].len;
      }
      if (st[v].nex[c-C]) {
        v = st[v].nex[c-C];
        ++l;
      }
      mx = max(mx, l);
    }
    return mx;
  }
};

SAM sam;
string s, t;

inline void solve() {
  cin >> s >> t;
  sam.init();
  for (char &c : s) sam.extend(c);
  cout << sam.lcs(t) << '\n';
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