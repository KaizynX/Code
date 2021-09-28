/*
 * @Author: Kaizyn
 * @Date: 2021-09-27 18:23:18
 * @LastEditTime: 2021-09-27 19:37:24
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
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 260817*2+7;

struct PAM {
  static const int A = 27;
  static const char C = 'a';
  int sz, tot, last;
  int ch[N][A], len[N], fail[N], vis[N];
  char s[N];
  PAM() { init(); }
  int node(int l) {
    ++sz;
    memset(ch[sz], 0, sizeof ch[sz]);
    len[sz] = l;
    fail[sz] = 0;
    return sz;
  }
  void init() {
    sz = -1;
    last = 0;
    s[tot = 0] = '$';
    node(0);
    fail[0] = node(-1);
  }
  int getfail(int x) {
    while (s[tot-len[x]-1] != s[tot]) x = fail[x];
    return x;
  }
  void insert(char c, int id) {
    s[++tot] = c;
    int now = getfail(last);
    if (!ch[now][c-C]) {
      int x = node(len[now]+2);
      fail[x] = ch[getfail(fail[now])][c-C];
      ch[now][c-C] = x;
    }
    last = ch[now][c-C];
    for (int i = last; i > 0; i = fail[i]) {
      if (vis[i]&id) break;
      vis[i] |= id;
    }
  }
  pii solve() {
    pii ans = pii{0, 0};
    for (int i = 2; i <= sz; ++i) {
      if (vis[i] != 3) continue;
      if (len[i] == ans.first) ++ans.second;
      else if (len[i] > ans.first) ans = pii{len[i], 1};
    }
    return ans;
  }
};

int n, m;
string s, t;
PAM pam;

inline void solve() {
  cin >> n >> m >> s >> t;
  pam.init();
  for (char c : s) pam.insert(c, 1);
  pam.insert('a'+26, 0);
  for (char c : t) pam.insert(c, 2);
  auto ans = pam.solve();
  cout << ans.first << ' ' << ans.second << '\n';
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