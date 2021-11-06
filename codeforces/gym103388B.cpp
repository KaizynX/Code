/*
 * @Author: Kaizyn
 * @Date: 2021-11-06 14:05:41
 * @LastEditTime: 2021-11-06 15:39:00
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
const int N = 2e5+7;

int n, m;
int nex[N], base[3], ans[N];
string s, t;
set<pii> st[3];
// 0 ++, 1 --, 2 equal
vector<pii> add[3][N];

void giao(int i, int j) {
  if (j == 0) return;
  if (j > n) j = n;
  add[2][i-n+1].emplace_back(j, i-j+1);
  add[1][i-j+1].emplace_back(j, i-j/2+1);
  add[0][i-j/2+1].emplace_back((j+1)/2, i);
}

inline void get_next(const string &s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline void kmp(const string &s1, const string &s2, int nex[]) {
  for (int i = 0, j = 0; i < (int)s1.size(); ++i) {
    while (j && s1[i] != s2[j]) j = nex[j];
    if (s1[i] == s2[j]) ++j;
    giao(i, j);
    if (j == (int)s2.size()) j = nex[j];
  }
}

inline void solve() {
  cin >> n >> m >> s;
  s += s;
  for (int i = 1; i <= m; ++i) {
    cin >> t;
    get_next(t, nex);
    kmp(s, t, nex);
  }
  for (int i : {0, 1, 2}) {
    base[i] = 0;
    st[i].clear();
    st[i].insert({-INF, 2*n});
  }
  for (int i = 0; i < 2*n; ++i, ++base[0], --base[1]) {
    for (int j : {0, 1, 2}) {
      for (pii p : add[j][i]) st[j].insert({p.first-base[j], p.second});
      while (st[j].rbegin()->second < i) st[j].erase(--st[j].end());
      ans[i%n] = max(ans[i%n], st[j].rbegin()->first+base[j]);
    }
  }
  #ifdef DEBUG
  orzarr(ans, n);
  #endif
  cout << *min_element(ans, ans+n) << '\n';
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