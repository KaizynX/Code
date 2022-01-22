/*
 * @Author: Kaizyn
 * @Date: 2022-01-22 22:33:50
 * @LastEditTime: 2022-01-22 23:49:27
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
const int N = 1e5 + 7;

int n;
string s[N];
set<string> st;

bool check(const string &s) {
  string t = s;
  reverse(t.begin(), t.end());
  return s == t;
}

inline bool solve() {
  st.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; ++i) {
    string t = s[i];
    reverse(t.begin(), t.end());
    if (s[i] == t) return true;
    if (st.find(t) != st.end()) return true;
    if (s[i].size() == 2u) {
      for (int i = 0; i < 26; ++i) {
        if (st.find(t + char('a' + i)) != st.end()) return true;
      }
    } else {
      t.pop_back();
      if (st.find(t) != st.end()) return true;
    }
    st.insert(s[i]);
  }
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}