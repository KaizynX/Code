/*
 * @Author: Kaizyn
 * @Date: 2021-10-16 12:20:59
 * @LastEditTime: 2021-10-16 12:35:03
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
const int N = 4;

int a[10];
string s;
stringstream ss;

void print(int u, int d, int opt) {
  int g = __gcd(abs(u), abs(d));
  u /= g;
  d /= g;
  if (d < 0) opt ^= 1, d = -d, u = -u;
  cout << 'x' << "><"[opt] << u;
  if (u != 0 && d != 1) cout << '/' << d;
  cout << '\n';
}

char spj(int v, int opt) {
  if (v == 0) return 'E';
  return (v < 0) == (opt == 0) ? 'R' : 'E';
}

inline void solve() {
  int x = -1;
  for (int i = 1; i <= 4; ++i) {
    cin >> s;
    if (s == "x") {
      x = i;
    } else {
      ss.clear();
      ss << s;
      ss >> a[i];
    }
  }
  if (x == 1 || x == 4) {
    if (x == 1) swap(a[4], a[1]);
    if (a[1] == 0) cout << spj(a[2]*a[3], 0) << '\n';
    else print(a[2]*a[3], a[1], 0);
  } else {
    if (x == 2) swap(a[2], a[3]);
    if (a[2] == 0) cout << spj(a[1]*a[4], 1) << '\n';
    else print(a[1]*a[4], a[2], 1);
  }
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