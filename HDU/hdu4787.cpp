/*
 * @Author: Kaizyn
 * @Date: 2020-05-22 11:26:21
 * @LastEditTime: 2020-05-22 14:09:59
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 5e6+7;

struct Aho_Corasick_Automaton {
  static const int NN = 2e5+7;
  static const int SZ = 2;
  char beg;
  int nex[NN][SZ], num[NN], fail[NN], cnt;
  Aho_Corasick_Automaton(const char &_beg = '0') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const char *s) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    num[p] = 1;
  }
  void build() {
    static queue<int> q;
    for (int i = 0; i < SZ; ++i) if (nex[0][i]) q.push(nex[0][i]);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < SZ; ++i) {
        if (nex[u][i]) {
          fail[nex[u][i]] = nex[fail[u]][i];
          q.push(nex[u][i]);
        } else {
          nex[u][i] = nex[fail[u]][i];
        }
      }
    }
  }
  int query(const char *s) {
    int len = strlen(s), p = 0, res = 0;
    for (int i = 0; i < len; ++i) {
      p = nex[p][s[i]-beg];
      for (int t = p; t; t = fail[t]) {
        res += num[t];
      }
    }
    return res;
  }
};

int n;
char buf[N], s[N];
Aho_Corasick_Automaton ac;

inline void shift(const char *buf, char *s, const int &k) {
  int len = strlen(buf);
  for (int i = 0; i < len; ++i) {
    // s[i] = buf[((i-k)%len+len)%len];
    s[i] = buf[(i+k)%len];
  }
  s[len] = '\0';
}

inline void solve() {
  ac.clear();
  scanf("%d", &n);
  for (int i = 1, k = 0; i <= n; ++i) {
    scanf("%s", buf);
    shift(buf+1, s, k);
    if (buf[0] == '+') {
      ac.insert(s);
    } else {
      // ac.build();
      printf("%d\n", k = ac.query(s));
    }
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("Case #%d:\n", t);
    solve();
  }
  return 0;
}