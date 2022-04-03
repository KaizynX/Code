/*
 * @Author: Kaizyn
 * @Date: 2022-03-30 15:50:13
 * @LastEditTime: 2022-03-30 16:18:34
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 4;

#define double long double

int t[N], p[N], b[N], pp[N];
double a[N];
double anss, ansa[N];
int ansp[N];

void update()  {
  #ifdef DEBUG
  orzarr(a, N);
  #endif
  double sum = a[0] * a[3] + a[1] + a[2];
  if (sum <= anss) return;
  anss = sum;
  memcpy(ansp, p, sizeof p);
  memcpy(ansa, a, sizeof a);
}

void fuck2() {
  if (b[1] <= 1) return;
  a[2] = (a[0] * a[3] - a[0] - a[3] + a[1]) / (a[1] - 1);
  if (a[2] >= 1 && a[2] <= b[2]) update();
}

void fuck3() {
  if (b[0] <= 1) return;
  a[3] = (a[1] * a[2] - a[1] - a[2] + a[0]) / (a[0] - 1);
  if (a[3] >= 1 && a[3] <= b[3]) update();
}

inline void solve() {
  anss = 3;
  iota(ansp, ansp + N, 0);
  fill(ansa, ansa + N, 1.0);

  for (int i = 0; i < N; ++i) scanf("%d", t + i);
  iota(pp, pp + N, 0);
  do {
    memcpy(p, pp, sizeof p);
    for (int i = 0; i < N; ++i) a[i] = b[i] = t[p[i]];
    fuck3();
    a[3] = a[2] = 1;
    update();
  } while (next_permutation(pp, pp + N));
  for (int i = 0; i < N; ++i) printf("%d%c", ansp[i] + 1, " \n"[i == N - 1]);
  for (int i = 0; i < N; ++i) printf("%.12Lf%c", ansa[i], " \n"[i == N - 1]);
}

signed main() {
#ifdef ONLINE_JUDGE
  // ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}