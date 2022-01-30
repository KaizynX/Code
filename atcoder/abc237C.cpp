/*
 * @Author: Kaizyn
 * @Date: 2022-01-30 20:17:09
 * @LastEditTime: 2022-01-30 20:19:00
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
const int N = 1e6 + 7;

string s;

inline void solve() {
  cin >> s;
  int n = s.size();
  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'a') ++l;
    else break;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == 'a') ++r;
    else break;
  }
  #ifdef DEBUG
  orz(l);
  orz(r);
  #endif
  reverse(s.begin(), s.end());
  while (l < r) {
    s += 'a';
    ++l;
  }
  string rs = s;
  reverse(rs.begin(), rs.end());
  if (s == rs) cout << "Yes\n";
  else cout << "No\n";
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