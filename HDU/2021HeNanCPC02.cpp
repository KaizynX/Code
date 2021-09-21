/*
 * @Author: Kaizyn
 * @Date: 2021-09-17 09:50:46
 * @LastEditTime: 2021-09-21 15:13:25
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

int k;
string s;
int nex[N], f[N];

inline void get_next(const string &s, int nex[]) {
  nex[0] = nex[1] = 0;
  for (int i = 1, j = 0; i < (int)s.size(); ++i) {
    while (j && s[i] != s[j]) j = nex[j];
    nex[i+1] = s[i] == s[j] ? ++j : 0;
  }
}

inline void solve() {
  cin >> s >> k;
  int n = s.size();
  get_next(s, nex);
  #ifdef DEBUG
  orzarr(nex, n+1);
  #endif
  for (int i = 1; i <= n; ++i) {
    f[i] = i%k == 0;
    int j = nex[i];
    int d = i-j;
    if (j+j <= i) continue;
    j = nex[j];
    if (j+j > i && j-nex[j] == d) {
      f[i] += f[j];
    } else { // brute
      for (j = nex[i]; j+j > i; j = nex[j]) f[i] += (j+j-i)%k == 0;
    }
  }
  #ifdef DEBUG
  orzarr(f, n+1);
  #endif
  ll ans = 1;
  for (int i = 1; i <= n; ++i) ans = ans*(f[i]+1)%MOD;
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
  }
  return 0;
}