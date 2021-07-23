/*
 * @Author: Kaizyn
 * @Date: 2021-07-23 15:01:42
 * @LastEditTime: 2021-07-23 15:33:47
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
const int N = 1e6+7;

int cnt[N<<1];

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
  void extend(char ch) {
    int c = ch-C, cur = sz++;
    st[cur].len = st[last].len+1;
    cnt[cur] = 1; // luogu3804
    int p = last;
    while (~p && !st[p].nex[c]) {
      st[p].nex[c] = cur;
      p = st[p].link;
    }
    if (p == -1) {
      st[cur].link = 0;
    } else {
      int q = st[p].nex[c];
      if (st[p].len+1 == st[q].len) {
        st[cur].link = q;
      } else {
        int clone = sz++;
        st[clone] = st[q];
        st[clone].len = st[p].len+1;
        while (~p && st[p].nex[c] == q) {
          st[p].nex[c] = clone;
          p = st[p].link;
        }
        st[q].link = st[cur].link = clone;
      }
    }
    last = cur;
  }
};

string s;
SAM sam;
vector<int> e[N<<1];

ll dfs(int u = 0) {
  ll res = 0;
  for (int v : e[u]) {
    res = max(res, dfs(v));
    cnt[u] += cnt[v];
  }
  if (cnt[u] > 1) res = max(res, 1ll*cnt[u]*sam.st[u].len);
  return res;
}

inline void solve() {
  cin >> s;
  sam.init();
  for (char &c : s) sam.extend(c);
  for (int i = 1; i < sam.sz; ++i) {
    e[sam.st[i].link].emplace_back(i);
  }
  cout << dfs() << '\n';
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