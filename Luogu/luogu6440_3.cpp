/*
 * @Author: Kaizyn
 * @Date: 2021-07-31 20:09:46
 * @LastEditTime: 2021-07-31 20:32:20
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
const int N = 2e5+7;

template <typename T, typename U = std::greater<T>>
struct ST {
  static const int NN = (int)log2(N)+3;
  static const T INF = 1e9;
  int lg2[N];
  U cmp = U();
  T rmq[N][NN];
  ST() {
    fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
  }
  T& operator [] (const int &i) { return rmq[i][0]; }
  void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
  T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
  // rmq[i][j] ==> [i, i+2^j-1]
  void build(T a[], const int &n) {
    for (int i = n; i; --i) {
      rmq[i][0] = a[i];
      for (int j = 1; j <= lg2[n-i+1]; ++j)
        rmq[i][j] =  mv(rmq[i][j-1], rmq[i+(1<<(j-1))][j-1]);
    }
  }
  T query(const int &l, const int &r) {
    if (l > r) return 0;
    int k = lg2[r-l+1];
    return mv(rmq[l][k], rmq[r-(1<<k)+1][k]);
  }
};

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
  void solve(const string &s, int f[]) {
    for (int i = 0, c, x = 0, l = 0; i < (int)s.size(); ++i) {
      c = s[i]-C;
      while (x && !st[x].nex[c]) {
        x = st[x].link;
        l = st[x].len;
      }
      if (st[x].nex[c]) {
        x = st[x].nex[c];
        ++l;
      }
      f[i+1] = l;
    }
  }
};

int n, q;
int f[N], g[N];
string s, t;
SAM sam;
ST<int, greater<int>> st;

inline void solve() {
  cin >> s >> t;
  n = s.size();
  sam.init();
  for (char ch : t) sam.extend(ch);
  sam.solve(s, f);
  st.build(f, n);
  for (int i = 1; i <= n; ++i) g[i] = i+1-f[i];
#ifdef DEBUG
  for (int i = 1; i <= n; ++i) cout << f[i] << " \n"[i==n];
  for (int i = 1; i <= n; ++i) cout << g[i] << " \n"[i==n];
#endif
  cin >> q;
  for (int _ = q, l, r; _; --_) {
    cin >> l >> r;
    // g[i] < l choose i-l+1 else choose f[i]
    int p = lower_bound(g+l, g+r+1, l)-g;
    cout << max(st.query(p, r), p-l) << '\n';
  }
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