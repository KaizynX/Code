/*
 * @Author: Kaizyn
 * @Date: 2022-06-11 20:31:30
 * @LastEditTime: 2022-06-11 20:51:59
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

using ll = long long;
using uint = unsigned;
using pii = pair<int, int>;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e5 + 7;

int n;
int P[N], I[N], L[N], R[N];
int Pr[N], Ir[N];

int build(int pl, int pr, int il, int ir) {
  if (pr - pl != ir - il) return -1;
  if (pl > pr) return 0;
  #ifdef DEBUG
  // cout << "build(" << pl << "," << pr << "," << il << "," << ir << ")\n";
  #endif
  // if (pl == pr) return P[pl];
  int rt = P[pl];
  int ip = Ir[rt];
  if (ip < il || ip > ir) return -1;
  int pp = pl + ip - il;
  L[rt] = build(pl + 1, pp, il, ip - 1);
  R[rt] = build(pp + 1, pr, ip + 1, ir);
  if (L[rt] == -1 || R[rt] == -1) return -1;
  return rt;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> P[i];
    Pr[P[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> I[i];
    Ir[I[i]] = i;
  }
  int flag = build(1, n, 1, n);
  if (flag != 1) {
    cout << "-1\n";
    return;
  }
  for (int i = 1; i <= n; ++i) {
    cout << L[i] << ' ' << R[i] << '\n';
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