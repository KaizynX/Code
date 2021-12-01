/*
 * @Author: Kaizyn
 * @Date: 2021-12-01 14:43:49
 * @LastEditTime: 2021-12-01 14:54:07
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
// vector<int> p[3];
set<int> p[3];
vector<pii> ans;

inline void solve() {
  cin >> n >> s;
  for (int i = 1, c; i <= 2*n; ++i) {
    c = s[i-1]-'A';
    p[c].insert(i);
  }
  int x = p[0].size()+p[1].size()-p[2].size();
  if (x%2 != 0) return cout << "NO\n", void();
  x /= 2;
  if (x < 0 || x > (int)p[1].size()) return cout << "NO\n", void();
  for (int i = 0; i < x; ++i) {
    auto k = *p[1].rbegin();
    p[1].erase(k);
    auto it = p[0].upper_bound(k);
    if (it == p[0].begin()) return cout << "NO\n", void();
    --it;
    ans.emplace_back(*it, k);
    p[0].erase(it);
  }
  for (auto k : p[1]) {
    auto it = p[2].lower_bound(k);
    if (it == p[2].end()) return cout << "NO\n", void();
    ans.emplace_back(k, *it);
    p[2].erase(it);
  }
  for (auto p0 = p[0].begin(), p2 = p[2].begin(); p0 != p[0].end(); ++p0, ++p2) {
    if (*p0 > *p2) return cout << "NO\n", void();
    ans.emplace_back(*p0, *p2);
  }
  cout << "YES\n";
  for (auto pp : ans) cout << pp.first << ' ' << pp.second << '\n';
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