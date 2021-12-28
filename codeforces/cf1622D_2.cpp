/*
 * @Author: Kaizyn
 * @Date: 2021-12-27 23:18:15
 * @LastEditTime: 2021-12-27 23:28:38
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
// const int N = ;

int n, k;
string s;
set<string> st;
vector<int> p;

inline void solve() {
  cin >> n >> k >> s;
  p.emplace_back(0);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '1') {
      p.emplace_back(i + 1);
    }
  }
  p.emplace_back(n + 1);
  int m = p.size();
  st.insert(s);
  for (int i = 1, l, r; i + k < m; ++i) {
    l = p[i - 1];
    r = p[i + k] - 1;
    string t = s;
    sort(t.begin() + l, t.begin() + r);
    do {
      st.insert(t);
    } while (next_permutation(t.begin() + l, t.begin() + r));
  }
  // for (auto &t : st) cout << t << '\n';
  cout << st.size() << '\n';
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