/*
 * @Author: Kaizyn
 * @Date: 2020-10-27 23:50:45
 * @LastEditTime: 2020-10-28 00:07:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 3e5+7;

struct Aho_Corasick_Automaton {
  static const int NN = 5e6+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], fail[NN], pos[N], cnt, sus[N];
  unordered_set<int> vis;
  multiset<int> val[NN];
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const char *s, int id) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    pos[id] = p;
    val[p].insert(sus[id] = 0);
  }
  void modify(int id, int x) {
    int p = pos[id];
    val[p].erase(val[p].find(sus[id]));
    val[p].insert(sus[id] = x);
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
    int len = strlen(s), p = 0, res = -1;
    vis.clear();
    for (int i = 0; i < len; ++i) {
      p = nex[p][s[i]-beg];
      // for (int t = p; t; t = fail[t]) {
      for (int t = p; t && !vis.count(t); t = fail[t]) {
        if (val[t].size()) res = max(res, *val[t].rbegin());
        vis.insert(t);
      }
    }
    return res;
  }
};

int n, m;
char s[N];
Aho_Corasick_Automaton ac;

inline void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    ac.insert(s, i);
  }
  for (int i = 1, op, id, x; i <= m; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d", &id, &x);
      ac.modify(id, x);
    } else {
      scanf("%s", s);
      printf("%d\n", ac.query(s));
    }
  }
}

signed main() {
  solve();
  return 0;
}