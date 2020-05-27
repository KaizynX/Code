/*
 * @Author: Kaizyn
 * @Date: 2020-05-21 22:58:46
 * @LastEditTime: 2020-05-22 10:03:11
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n;
int a[N];

struct Aho_Corasick_Automaton {
  static const int NN = 1e5+7;
  static const int SZ = 26;
  char beg;
  int cnt;
  int nex[NN][SZ], fail[NN], pre[NN], vis[NN], chr[NN];
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    memset(vis, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  int insert(const char *s) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt, pre[cnt] = p, chr[cnt] = c;
      p = nex[p][c];
    }
    return p;
  }
  void build() {
    static queue<int> q;
    for (int i = 0; i < 26; ++i) if (nex[0][i]) q.push(nex[0][i]);
    while (q.size()) {
      int u = q.front();
      q.pop();
      for (int i = 0; i < 26; ++i) {
        if (nex[u][i]) {
          fail[nex[u][i]] = nex[fail[u]][i];
          q.push(nex[u][i]);
        } else {
          nex[u][i] = nex[fail[u]][i];
        }
      }
    }
  }
  void query(char *s) {
    int len = strlen(s);
    for (int i = 0, p = 0; i < len; ++i) {
      p = nex[p][s[i]-beg];
      for (int t = p; t; t = fail[t]) {
        ++vis[t];
      }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      res = max(res, vis[a[i]]);
    }
    printf("%d\n", res);
    for (int i = 1; i <= n; ++i) {
      if (vis[a[i]] != res) continue;
      len = 0;
      for (int p = a[i]; p; p = pre[p]) {
        s[len++] = chr[p]+'a';
      }
      reverse(s, s+len);
      s[len] = '\0';
      puts(s);
    }
  }
} ac;

signed main() {
  static char s[N];
  while (scanf("%d", &n) == 1 && n) {
    ac.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s);
      a[i] = ac.insert(s);
    }
    scanf("%s", s);
    ac.build();
    ac.query(s);
  }
  return 0;
}