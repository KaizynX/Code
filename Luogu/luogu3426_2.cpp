/*
 * @Author: Kaizyn
 * @Date: 2021-08-23 15:17:49
 * @LastEditTime: 2021-08-23 15:52:19
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
const int N = 5e5+7;

int n;
string s;
set<int> st;
multiset<int> gap;
vector<pii> p;

vector<int> z_function(string s) {
  int n = (int)s.length();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r && z[i - l] < r - i + 1) {
      z[i] = z[i - l];
    } else {
      z[i] = max(0, r - i + 1);
      while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    }
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

inline void solve() {
  cin >> s;
  n = s.size();
  auto z = z_function(s);
  for (int i = 1; i < n; ++i) {
    p.emplace_back(z[i], i);
  }
  sort(p.begin(), p.end());
  st.insert(0);
  st.insert(n);
  gap.insert(n);
  int ans = n;
#ifdef DEBUG
  orzeach(z);
  orzeach(p);
#endif
  for (int i = n-1; i; --i) if (z[n-i] == i) {
    while (p.size() && p.back().first >= i) {
      int k = p.back().second;
      auto it = st.upper_bound(k);
      int r = *it, l = *(--it);
      gap.erase(gap.find(r-l));
      gap.insert(r-k);
      gap.insert(k-l);
      st.insert(k);
      p.pop_back();
    }
    #ifdef DEBUG
    orz(i);
    orzeach(st);
    orzeach(gap);
    #endif
    if (*gap.rbegin() <= i) ans = i;
  }
  cout << ans << '\n';
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