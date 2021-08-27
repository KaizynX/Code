/*
 * @Author: Kaizyn
 * @Date: 2021-08-24 23:22:30
 * @LastEditTime: 2021-08-24 23:41:27
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
const int N = 4e6+7;

int n, P;
int add[N], f[N];

void brute() {
  f[1] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) (f[j] += f[i]) %= MOD;
    for (int j = 2; i*j <= n; ++j) { // k/j == i
      for (int k = j*i; k < j*i+j; ++k) {
        (f[k] += f[i]) %= MOD;
      }
    }
  }
  cout << f[n] << '\n';
}

inline void solve() {
  cin >> n >> P;
  // brute();
  add[1] = 1; add[2] = -1;
  for (int i = 1; i <= n; ++i) {
    f[i] = (f[i-1]+add[i])%P;
    (add[i+1] += f[i]) %= P;
    for (int j = 2; i*j <= n; ++j) {
      (add[j*i] += f[i]) %= P;
      if (j*i+j <= n) (add[j*i+j] -= f[i]) %= P;
    }
  }
  f[n] = (f[n]+P)%P;
  cout << f[n] << '\n';
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