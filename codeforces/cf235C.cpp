/*
 * @Author: Kaizyn
 * @Date: 2021-08-08 16:16:26
 * @LastEditTime: 2021-08-08 19:16:06
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
#define log(x) (31-__builtin_clz(x))
const int N = 1e6+7;
const int LOGN = log(N)+2;

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
  SAM() { init(); }
  int sz, last;
  int d[N], f[N][LOGN];
  vector<int> e[N];
  ll cnt[N];
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
    cnt[last = cur] = 1;
  }
  void dfs(int u) {
    for (int i = 1; (1<<i) <= d[u]; ++i)
      f[u][i] = f[f[u][i-1]][i-1];
    for (int v : e[u]) {
      f[v][0] = u;
      d[v] = d[u]+1;
      dfs(v);
      cnt[u] += cnt[v];
    }
  }
  void build() {
    for (int i = 1; i < sz; ++i) e[st[i].link].emplace_back(i);
    d[0] = 1;
    dfs(0);
    #ifdef DEBUG
    for (int i = 0; i < sz; ++i) {
      cout << cnt[i] << " \n"[i==sz-1];
    }
    #endif
  }
  ll solve(const string &t) {
    ll res = 0;
    int v = 0, l = 0, n = t.size();
    for (int i = 0; i < 2*n-1; ++i) {
      int c = t[i%n]-C;
      while (v && !st[v].nex[c]) {
        v = st[v].link;
        l = st[v].len;
      }
      if (st[v].nex[c]) {
        v = st[v].nex[c];
        ++l;
      }
      if (l >= n) {
        int j = v;
        for (int b = log(d[j]); b >= 0; --b) {
          if (st[f[j][b]].len >= n) j = f[j][b];
        }
        res += cnt[j];
      }
    }
    return res;
  }
};

int n;
string s;
SAM sam;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> s >> n;
  for (char ch : s) sam.extend(ch);
  sam.build();
  for (int _ = n; _; --_) {
    cin >> s;
    cout << sam.solve(s) << '\n';
  }
  return 0;
}