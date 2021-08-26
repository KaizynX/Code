/*
 * @Author: Kaizyn
 * @Date: 2021-08-25 20:51:55
 * @LastEditTime: 2021-08-26 13:16:23
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
const int N = 5e3+7;

void update(int &x, int y) {
  if (y == -1) return;
  if (x == -1 || y < x) x = y;
}

struct SAM { // root 0
  static const int A = 26;
  static const int M = N<<1;
  static const char C = 'a';
  int sz, last, len[M], link[M], nex[M][A];
  int vis[M], cnt[M], mnl[M];
  void init() {
    memset(nex, 0, sizeof(int)*A*sz);
    link[0] = -1; sz = 1; last = 0;
  }
  int extend(int c) {
    int cur = sz++, p = last;
    len[cur] = len[last]+1;
    for (; ~p && !nex[p][c]; p = link[p]) nex[p][c] = cur;
    if (p == -1) return link[cur] = 0, cur;
    int q = nex[p][c];
    if (len[p]+1 == len[q]) return link[cur] = q, cur;
    int clone = sz++;
    memcpy(nex[clone], nex[q], sizeof nex[q]);
    link[clone] = link[q];
    len[clone] = len[p]+1;
    for (; ~p && nex[p][c] == q; p = link[p]) nex[p][c] = clone;
    link[q] = link[cur] = clone;
    return cur;
  }
  void insert(const string &s) {
    init(); for (char ch : s) ++cnt[last = extend(ch-C)];
  }
  void build() { // topo on parent tree
    static int t[M], rk[M];
    memset(t, 0, sizeof(int)*sz);
    for (int i = 0; i < sz; ++i) ++t[len[i]];
    for (int i = 1; i < sz; ++i) t[i] += t[i-1];
    for (int i = 0; i < sz; ++i) rk[--t[len[i]]] = i;
    for (int _ = sz-1, i, j; _; --_) { // assert(rk[0] == 0);
      i = rk[_];
      j = link[i];
      cnt[j] += cnt[i];
    }
    mnl[0] = -1;
    for (int _ = 1, i, j; _ < sz; ++_) {
      i = rk[_];
      j = link[i];
      mnl[i] = cnt[i] == 1 ? len[j]+1 : -1;
      update(mnl[i], mnl[j]);
    }
  }
};

string s, t;
SAM sams, samt;

int f(int si, int ti, int l) {
  si = sams.mnl[si];
  ti = samt.mnl[ti];
  if (si == -1 || ti == -1) return -1;
  si = max(si, ti);
  return si <= l ? si : -1;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> s >> t;
  sams.insert(s);
  samt.insert(t);
  sams.build();
  samt.build();
  int ans = -1;
  for (int i = 0, si = 0, ti = 0, l = 0; i < (int)s.size(); ++i) {
    int c = s[i]-'a';
    si = sams.nex[si][c];
    while (ti && !samt.nex[ti][c]) l = samt.len[ti = samt.link[ti]];
    if (samt.nex[ti][c]) ti = samt.nex[ti][c], ++l;
    update(ans, f(si, ti, l));
    #ifdef DEBUG
    printf("i=%d,l=%d,ls=%d,lt=%d,ans=%d\n", i, l, sams.mnl[si], samt.mnl[ti], ans);
    #endif
  }
  cout << ans << '\n';
  return 0;
}