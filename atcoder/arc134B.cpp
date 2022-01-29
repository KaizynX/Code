/*
 * @Author: Kaizyn
 * @Date: 2022-01-29 19:56:20
 * @LastEditTime: 2022-01-29 20:34:51
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
const int N = 2e5 + 7;

int n;
int cnt[26];
string s;

inline void solve() {
  cin >> n >> s;
  for (char c : s) ++cnt[c - 'a'];
  int l = 0, r = n - 1, mn = 0;
  --cnt[s[0] - 'a'];
  while (l < r) {
    while (cnt[mn] == 0) ++mn;
    if (s[l] - 'a' <= mn) {
      --cnt[s[++l] - 'a'];
      continue;
    }
    while (l < r && s[r] - 'a' != mn) --cnt[s[r--] - 'a'];
    if (l >= r) break;
    assert(s[l] > s[r]);
    --cnt[s[r] - 'a'];
    swap(s[l], s[r--]);
    --cnt[s[++l] - 'a'];
  }
  cout << s << '\n';
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
bcaca
acbca
*/