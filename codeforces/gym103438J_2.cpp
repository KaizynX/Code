/*
 * @Author: Kaizyn
 * @Date: 2021-12-01 14:28:19
 * @LastEditTime: 2021-12-01 14:33:55
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
const int N = 1e5+7;

int n;
string s;
vector<int> p[3];
vector<pii> pr[3][3];

inline void solve() {
  cin >> n >> s;
  for (int i = 1, c; i <= 2*n; ++i) {
    c = s[i-1]-'A';
    if (c == 0) {
      p[0].emplace_back(i);
    } else if (c == 1) {
      if (p[0].size()) { // "AB" 可反悔
        pr[0][1].emplace_back(p[0].back(), i);
        p[0].pop_back();
      } else {
        p[1].emplace_back(i);
      }
    } else {
      if (p[1].size()) { // B 只能  "BC"
        pr[1][2].emplace_back(p[1].back(), i);
        p[1].pop_back();
      } else if (pr[0][1].size()) {
        p[0].emplace_back(pr[0][1].back().first);
        pr[1][2].emplace_back(pr[0][1].back().second, i);
        pr[0][1].pop_back();
      } else if (p[0].size()) {
        pr[0][2].emplace_back(p[0].back(), i);
        p[0].pop_back();
      } else {
        return cout << "NO\n", void();
      }
    }
  }
  while (p[0].size() > 1) {
    if (pr[1][2].size()) {
      int pb = pr[1][2].back().first;
      int pc = pr[1][2].back().second;
      pr[1][2].pop_back();
      if (pc > p[0].back()) {
        pr[0][2].emplace_back(p[0].back(), pc);
        p[0].pop_back();
      } else {
        break;
      }
      if (pb > p[0].back()) {
        pr[0][1].emplace_back(p[0].back(), pb);
        p[0].pop_back();
      } else {
        break;
      }
    } else {
      break;
    }
  }
  for (int i : {0, 1, 2}) if (p[i].size()) return cout << "NO\n", void();
  cout << "YES\n";
  for (int i = 0; i < 3; ++i) for (int j = i+1; j < 3; ++j) {
    for (auto pp : pr[i][j]) {
      cout << pp.first << ' ' << pp.second << '\n';
    }
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
/*
3
ABACBB
6
ABACABABACBB
*/