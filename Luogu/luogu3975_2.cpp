/*
 * @Author: Kaizyn
 * @Date: 2021-07-25 14:27:26
 * @LastEditTime: 2021-07-25 15:10:13
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
const int N = 5e5+7;

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
  ll num[N<<1], sum[N<<1], vis[N<<1];
  vector<int> e[N<<1];
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
    sum[cur] = num[cur] = 1;
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
  void dfs1(int u) {
    for (int &v : e[u]) {
      dfs1(v);
      num[u] += num[v];
    }
  }
  void dfs2(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    sum[u] = num[u];
    for (int i = 0, v; i < A; ++i) {
      v = st[u].nex[i];
      if (v) {
        dfs2(v);
        sum[u] += sum[v];
      }
    }
  }
  void build(int t) {
    for (int i = 1; i < sz; ++i) e[st[i].link].emplace_back(i);
    if (t) dfs1(0);
    else for(int i = 0; i < sz; ++i) num[i] = sum[i] = 1;
    num[0] = sum[0] = 0;
    dfs2(0);
    #ifdef DEBUG
    for (int i = 0; i < sz; ++i) cout << num[i] << " \n"[i==sz-1];
    for (int i = 0; i < sz; ++i) cout << sum[i] << " \n"[i==sz-1];
    #endif
  }
  void query(int k, int u = 0) {
    if (k > sum[u]) return puts("-1"), void();
    if (k <= num[u]) return puts(""), void();
    k -= num[u];
    for (int i = 0, v; i < A; ++i) {
      v = st[u].nex[i];
      if (!v) continue;
      if (k > sum[v]) k -= sum[v];
      else return putchar('a'+i), query(k, v);
    }
  }
};

string s;
int t, k;
SAM sam;

inline void solve() {
  cin >> s >> t >> k;
  sam.init();
  for (char &ch : s) sam.extend(ch);
  sam.build(t);
  sam.query(k);
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