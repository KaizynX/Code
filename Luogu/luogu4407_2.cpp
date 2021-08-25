/*
 * @Author: Kaizyn
 * @Date: 2021-08-25 20:08:52
 * @LastEditTime: 2021-08-25 20:28:50
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;
namespace hjt {
template<typename A,typename B>
std::ostream &operator<<(std::ostream &o,const std::pair<A,B> &x){
  return o<<'('<<x.first<<','<<x.second<<')';
}
#define repeat(i,a,b) for(int i=(a),_=(b);i<_;i++)
#define repeat_back(i,a,b) for(int i=(b)-1,_=(a);i>=_;i--)
#define qwq [&]{cerr<<"qwq"<<endl;}()
#define orz(x) [&]{cerr<<#x": "<<x<<endl;}()
#define orzarr(a,n) [&]{cerr<<#a": "; repeat(__,0,n)cerr<<(a)[__]<<" "; cerr<<endl;}()
#define orzeach(a) [&]{cerr<<#a": "; for(auto __:a)cerr<<__<<" "; cerr<<endl;}()
#define pause [&]{system("pause");}()
} using namespace hjt;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e4+7;

struct TireTree {
  static const int NN = N*20;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], num[NN], cnt, vis[NN];
  char *str;
  TireTree(char _beg = 'a') : beg(_beg) { clear(); }
  void clear() {
    memset(nex, 0, sizeof nex);
    memset(num, 0, sizeof num);
    cnt = 0;
  }
  void insert(const char *s) {
    int p = 0;
    for (int i = 0, c; s[i]; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    ++num[p];
  }
  /*
  void dfs(int i, int p, int r) {
    if (r < 0) return;
    if (p == 0 && i != 0) return;
    int c = str[i]-beg;
    if (str[i] == 0) {
      if (r == 0) vis[p] = 1;
      else for (int j = 0; j < SZ; ++j) vis[nex[p][j]] = 1;
      return;
    }
    dfs(i+1, p, r-1);
    for (int j = 0; j < SZ; ++j) {
      dfs(i, nex[p][j], r-1);
      dfs(i+1, nex[p][j], r-(c != j));
    }
  }
  */
  void dfs(int i, int p, int r) {
    int c = str[i]-beg;
    if (str[i] == 0) {
      if (r == 0) vis[p] = 1;
      else for (int j = 0; j < SZ; ++j) vis[nex[p][j]] = 1;
      return;
    }
    if (nex[p][c]) dfs(i+1, nex[p][c], r);
    if (r == 0) return;
    dfs(i+1, p, 0);
    for (int j = 0; j < SZ; ++j) if (nex[p][j]) {
      dfs(i, nex[p][j], 0);
      if (c != j) dfs(i+1, nex[p][j], 0);
    }
  }
  int query(char *s) {
    if (find(s)) return -1;
    str = s;
    dfs(0, 0, 1);
    int ans = 0;
    for (int i = 1; i <= cnt; ++i) {
      if (vis[i]) ans += num[i];
      vis[i] = 0;
    }
    return ans;
  }
  bool find(const char *s) {
    int p = 0;
    for (int i = 0, c; s[i]; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) return false;
      p = nex[p][c];
    }
    return num[p];
  }
};

int n, m;
char s[25];
TireTree tree;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    tree.insert(s);
  }
  for (int i = 1; i <= m; ++i) {
    scanf("%s", s);
    printf("%d\n", tree.query(s));
  }
  return 0;
}