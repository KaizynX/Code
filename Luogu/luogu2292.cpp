/*
 * @Author: Kaizyn
 * @Date: 2021-08-23 20:43:58
 * @LastEditTime: 2021-08-23 21:12:35
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
const int N = 2e6+7;

int n, m;
char s[N];
int f[N];

struct Aho_Corasick_Automaton {
  static const int NN = 5e2+7;
  static const int SZ = 26;
  char beg;
  int nex[NN][SZ], ed[NN], fail[NN], cnt, len[NN], jmp[NN];
  Aho_Corasick_Automaton(const char &_beg = 'a') : beg(_beg) {}
  void clear() {
    memset(nex, 0, sizeof(nex[0])*(cnt+1));
    memset(fail, 0, sizeof(int)*(cnt+1));
    cnt = 0;
  }
  void insert(const char *s) {
    int p = 0;
    for (int i = 0, c; s[i]; ++i) {
      c = s[i]-beg;
      if (!nex[p][c]) nex[p][c] = ++cnt;
      p = nex[p][c];
      len[p] = i;
    }
    ed[p] = 1;
  }
  void build() {
    static queue<int> q;
    for (int i = 0; i < SZ; ++i) if (nex[0][i]) q.push(nex[0][i]);
    while (q.size()) {
      int u = q.front();
      jmp[u] = jmp[fail[u]]|(ed[u]<<len[u]);
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
    int last = 1, ans = 0;
    for (int i = 0, p = 0; s[i]; ++i) {
      // while (p && !nex[p][s[i]-beg]) p = fail[p];
      p = nex[p][s[i]-beg];
      if (!p) break;
      f[i] = bool(last&jmp[p]);
      if (f[i]) ans = max(ans, i+1);
      #ifdef DEBUG
      orz(i); orz(p); orz(f[i]);
      cout << bitset<11>(last) << ' ' << bitset<11>(jmp[p]) << '\n';
      #endif
      last = (last<<1)|f[i];
    }
    #ifdef DEBUG
    cout << '\n';
    for (int i = 0; s[i]; ++i) cout << f[i];
    cout << '\n';
    #endif
    return ans;
  }
};

Aho_Corasick_Automaton ac;

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    ac.insert(s);
  }
  ac.build();
  for (int _ = m; _; --_) {
    scanf("%s", s);
    printf("%d\n", ac.query(s));
  }
  return 0;
}