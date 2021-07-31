/*
 * @Author: Kaizyn
 * @Date: 2021-07-31 20:02:38
 * @LastEditTime: 2021-07-31 21:28:07
 */
#include <cstring>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

typedef long long ll;
const int N = 1e5+7;

int k;

struct SAM {
  static const int A = 26;
  static const char C = 'a';
  static const int M = N<<1;
  struct State {
    int len, link, nex[A];
    State& operator =(const State &st) {
      len = st.len;
      link = st.link;
      memcpy(nex, st.nex, sizeof(nex));
      return *this;
    }
  } st[N<<1];
  int sz, last, cnt[M], t[M], rk[M];
  ll dp[M];
  void init() {
    memset(st, 0, sizeof(State)*sz);
    memset(t, 0, sizeof(int)*sz);
    memset(cnt, 0, sizeof(int)*sz);
    st[0].len = 0;
    st[0].link = -1;
    sz = 1;
    last = 0;
  }
  void extend(char ch) {
    int c = ch-C, cur = sz++;
    st[cur].len = st[last].len+1;
    cnt[cur] = 1;
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
  void build() {
    for (int i = 0; i < sz; ++i) ++t[st[i].len];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[st[i].len]] = i;
    for (int _ = sz-1, i, j; _ >= 0; --_) {
      i = rk[_];
      if (!i) continue;
      j = st[i].link;
      cnt[j] += cnt[i];
    }
    for (int _ = 0, i, j; _ < sz; ++_) {
      i = rk[_];
      if (!i) continue;
      j = st[i].link;
      dp[i] = dp[j];
      if (st[i].len >= k) {
        dp[i] += 1ll*min(st[i].len-st[j].len, st[i].len-k+1)*cnt[i];
      }
    }
    #ifdef DEBUG
    for (int i = 0; i < sz; ++i) cout << cnt[i] << " \n"[i==sz-1];
    for (int i = 0; i < sz; ++i) cout << dp[i] << " \n"[i==sz-1];
    #endif
  }
  ll solve(const string &s) {
    ll res = 0;
    for (int i = 0, c, x = 0, l = 0, y; i < (int)s.size(); ++i) {
      c = s[i]-C;
      while (x && !st[x].nex[c]) {
        x = st[x].link;
        l = st[x].len;
      }
      if (st[x].nex[c]) {
        ++l;
        x = st[x].nex[c];
      }
      if (!x) continue;
      y = st[x].link;
      res += dp[y];
      if (l >= k) res += 1ll*min(l-st[y].len, l-k+1)*cnt[x];
      #ifdef DEBUG
      printf("i=%d,x=%d,l=%d,cnt=%d,res=%lld\n", i, x, l, cnt[x], res);
      #endif
    }
    return res;
  }
};

string A, B;
SAM sam;

inline void solve() {
  cin >> A >> B;
  sam.init();
  for (int i = 0; i < (int)A.size(); ++i) sam.extend(A[i]);
  sam.build();
  cout << sam.solve(B) << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
  while (cin >> k && k) solve();
  return 0;
}