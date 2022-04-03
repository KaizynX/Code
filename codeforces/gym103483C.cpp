/*
 * @Author: Kaizyn
 * @Date: 2022-03-30 17:00:11
 * @LastEditTime: 2022-03-30 17:57:28
 */
#include <bits/stdc++.h>

#define DEBUG

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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 1e6 + 7;
constexpr int LOGN = 20;

#define _log(x) (31-__builtin_clz(x))

int n, q;
char s[N], t[N];

struct TireTree {
  static const int NN = N;
  static const int SZ = 26;
  char beg;
  int tmp, cnt, pos;
  int nex[NN][SZ], num[NN], dep[NN], sum[NN], leaf[NN][SZ], fa[NN][LOGN];
  vector<pair<int, int>> stk;
  TireTree(char _beg = 'a') : beg(_beg) { clear(); }
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(num, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const char *s) {
    int len = strlen(s), p = 0;
    for (int i = 0, c; i < len; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
    }
    ++num[p];
  }
  void dfs(int p = 0) {
    if (dep[p]) for (int i = 1; i <= _log(dep[p]); ++i) {
      fa[p][i] = fa[fa[p][i - 1]][i - 1];
    }
    tmp += num[p]; // <=
    sum[p] = tmp;
    for (int i = 0; i < SZ; ++i) {
      if (nex[p][i]) {
        dep[nex[p][i]] = dep[p] + 1;
        fa[nex[p][i]][0] = p;
        dfs(nex[p][i]);
        leaf[p][i] = leaf[nex[p][i]][i];
      } else {
        leaf[p][i] = p;
      }
    }
    #ifdef DEBUG
    orz(p);
    orz(sum[p]);
    orzarr(leaf[p], 26);
    #endif
  }
  int build(const char *s)  {
    int len = strlen(s), p = 0;
    for (int i = 0, c, flag = 1; i < len; ++i) {
      c = s[i]-beg;
      stk.emplace_back(i + 1, p);
      if (!nex[p][c]) flag = 0;
      if (flag) p = nex[p][c];
    }
    pos = p;
    return sum[p] - (n == dep[p]) * num[p];
  }
  int query(int k, char c) {
    #ifdef DEBUG
    orz(pos);
    #endif
    int p = pos;
    while (stk.size() && stk.back().first >= k) {
      p = stk.back().second;
      stk.pop_back();
    }
    int dis = dep[p] - k + 1;
    if (dis > 0) for (int i = LOGN - 1; i >= 0; --i) {
      if ((dis >> i) & 1) {
        dis ^= 1 << i;
        p = fa[p][i];
      }
    }
    #ifdef DEBUG
    orz(pos);
    #endif
    stk.emplace_back(k, p);
    if (dep[p] == k - 1) p = leaf[p][c - beg];
    pos = p;
    return sum[p] - (n == dep[p]) * num[p];
  }
} tree;

inline void solve() {
  scanf("%d%d", &n, &q);
  scanf("%s", s);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", t);
    tree.insert(t);
  }
  n = strlen(s);
  tree.dfs(0);
  printf("%d\n", tree.build(s));
  for (int i = 1, k; i <= q; ++i) {
    scanf("%d%s", &k, t);
    printf("%d\n", tree.query(k, t[0]));
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