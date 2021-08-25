/*
 * @Author: Kaizyn
 * @Date: 2021-08-25 19:21:54
 * @LastEditTime: 2021-08-25 20:08:20
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
  int nex[NN][SZ], num[NN], cnt;
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
  int dfs(int i, int p, int r) {
    if (str[i] == '\0') {
      if (r == 0) return num[p];
      int sum = 0;
      for (int j = 0; j < SZ; ++j) {
        if (nex[p][j]) sum += num[nex[p][j]];
      }
      return sum;
    }
    int c = str[i]-beg, sum = 0;
    if (nex[p][c]) sum = dfs(i+1, nex[p][c], r);
    if (r == 0) return sum;
    sum += dfs(i+1, p, 0);
    for (int j = 0; j < SZ; ++j) {
      if (j == c || nex[p][j] == 0) continue;
      sum += dfs(i, nex[p][j], 0)+dfs(i+1, nex[p][j], 0);
    }
    return sum;
  }
  */
  int dfs(int i, int p, int r) {
    if (r < 0) return 0;
    if (p == 0 && i != 0) return 0;
    int c = str[i]-beg, sum = 0;
    if (str[i] == 0) {
      if (r == 0) sum = num[p];
      else for (int j = 0; j < SZ; ++j) sum += num[nex[p][j]];
    #ifdef DEBUG
    if (sum) printf("dfs(%d,%d,%d)=%d\n", i, p, r, sum);
    #endif
      return sum;
    }
    sum += dfs(i+1, p, r-1);
    for (int j = 0; j < SZ; ++j) {
      sum += dfs(i, nex[p][j], r-1);
      sum += dfs(i+1, nex[p][j], r-(c != j));
    }
    #ifdef DEBUG
    if (sum) printf("dfs(%d,%d,%d)=%d\n", i, p, r, sum);
    #endif
    return sum;
  }
  int query(char *s) {
    if (find(s)) return -1;
    str = s;
    return dfs(0, 0, 1);
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