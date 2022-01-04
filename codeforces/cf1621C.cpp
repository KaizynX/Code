/*
 * @Author: Kaizyn
 * @Date: 2022-01-03 22:54:52
 * @LastEditTime: 2022-01-03 23:20:07
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
const int N = 1e4+7;

int n;
int p[N];
vector<int> stk;

int query(int x) {
  cout << "? " << x << endl;
  cin >> x;
  return x;
}

inline void solve() {
  cin >> n;
  memset(p + 1, 0, sizeof(int) * n);
  stk.clear();
  for (int t = 0, s = 1; s <= n; ++t) {
    stk.emplace_back(query(s));
    if (stk.size() > 1u && stk.back() == stk.front()) {
      stk.pop_back();
      rotate(stk.begin(), find(stk.begin(), stk.end(), s), stk.end());
      int sz = stk.size();
      for (int i = 0; i < sz; ++i) {
        p[stk[i]] = stk[(i + 1) % sz];
      }
      while (++s) {
        if (s > n) break;
        if (p[s]) continue;
        else break;
      }
      #ifdef DEBUG
      orz(s);
      orzeach(stk);
      #endif
      stk.clear();
    }
  }

  cout << "!";
  for (int i = 1; i <= n; ++i) cout << ' ' << p[i];
  cout << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}