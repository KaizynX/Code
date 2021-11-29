/*
 * @Author: Kaizyn
 * @Date: 2021-11-26 18:31:37
 * @LastEditTime: 2021-11-26 18:36:45
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
const int N = 1e6+7;

int n, m;
string s;
vector<int> p[N<<1];

inline void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) if (s[j] == '1') {
      p[i+j].emplace_back(j-i);
    }
  }
  int ans = 0;
  for (int id : {0, 1}) {
    vector<int> lis;
    for (int i = id; i < n+m; i += 2) {
      sort(p[i].rbegin(), p[i].rend());
      for (int x : p[i]) {
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) lis.emplace_back(x);
        else *it = x;
      }
    }
    ans += lis.size();
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
    for (int i = 0; i < n+m; ++i) p[i].clear();
  }
  return 0;
}