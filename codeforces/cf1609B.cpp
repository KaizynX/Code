/*
 * @Author: Kaizyn
 * @Date: 2021-11-28 22:27:33
 * @LastEditTime: 2021-11-28 22:48:54
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

int n, q;
string s;
set<int> st;

int check(int i) {
  if (i < 0 || i+2 >= n) return 0;
  return s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c';
}

inline void solve() {
  cin >> n >> q >> s;
  for (int i = 0; i < n; ++i) {
    if (check(i)) st.insert(i);
  }
  for (int i = 1, p; i <= q; ++i) {
    char c;
    cin >> p >> c;
    --p;
    if (c != s[p]) {
      s[p] = c;
      auto it = st.lower_bound(p-2);
      if (it != st.end() && *it <= p) st.erase(it);
      for (int j = p-2; j <= p; ++j) {
        if (check(j)) st.insert(j);
      }
    }
    #ifdef DEBUG
    orzeach(st);
    #endif
    cout << st.size() << '\n';
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