/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 20:19:57
 * @LastEditTime: 2020-08-15 20:44:33
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

struct TireTree {
  static const int NN = 2e6+7;
  static const int SZ = 2;
  char beg = '0';
  long long val[NN], sum[NN];
  int cnt;
  vector<int> nex[NN][SZ];
  void clear() {
    for (int i = 1; i <= cnt; ++i) {
      vector<int>().swap(nex[i][0]);
      vector<int>().swap(nex[i][1]);
      val[i] = sum[i] = 0;
    }
    cnt = 0;
  }
  void insert(const char *s, const int &val) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (nex[p][c].empty()) nex[p][c].emplace_back(++cnt);
      p = nex[p][c].front();
      ++sum[p];
    }
    val[p] += val;
  }
  int erase(const char *s, const int &p = 0) {
    if (s[0] == '\0') return 1;
    int c = s[0]-beg;
    if (nex[p][c].empty()) return 0;
    int flag = 1;
    for (const int &np : nex[p][c]) {
      flag &= erase(s+1, np);
    }
    if (flag) nex[p][c].clear();
    return flag;
  }
  long long query(const char *s, const int &p = 0) {
    if (s[0] == '\0') return sum[p];
    int c = s[0]-beg;
    if (nex[p][c].empty()) return -1;
    long long res = -1;
    for (const int &np : nex[p][c]) {
      long long nv = query(s+1, np);
      if (nv == -1) continue;
      if (res == -1) res = 0;
      res += nv;
    }
    return res;
  }
};

int n;
char s[N], t[N];
TireTree tree;

inline void solve() {
  scanf("%d", &n);
  tree.clear();
  char op[10];
  for (int i = 1, sum = 0, v; i <= n; ++i) {
    scanf("%s%s", op, s);
    char opt = op[0];
    if (opt == 'I') {
      scanf("%d", &v);
      tree.insert(s, v);
    } else if (opt == 'D') {
      if (tree.erase(s) == -1) puts("Not Exist");
    } else if (opt == 'Q') {
      long long res = tree.query(s);
      if (res == -1) puts("Not Exist");
      else printf("%lld\n", res);
    } else if (opt == 'U') {
      scanf("%s", t);
      if (tree.update(s, t) == -1) puts("Not Exist");
    }
    if ((sum += s.size()) > 2333) {
      tree.rebuild();
      sum = 0;
    }
  }
}

signed main() {
  int T = 1;
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    printf("Case %d\n", t);
    solve();
  }
  return 0;
}