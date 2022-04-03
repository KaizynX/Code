/*
 * @Author: Kaizyn
 * @Date: 2022-03-23 13:18:51
 * @LastEditTime: 2022-03-23 13:42:39
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
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 2e3 + 7;

int n;
int mo, mm, L, R;
int sum[N];
string s, t;

void update(int mat, int l, int r) {
  ++l; ++r;
  mat = mo + mat - (sum[r] - sum[l - 1]);
  if (mat < mm) return;
  if (mat == mm) {
    if (r - l < R - L) {
      R = r;
      L = l;
      return;
    } else if (r - l == R - L) {
      if (l < L) {
        L = l;
        R = r;
      }
    }
  }
  if (mat > mm) {
    mm = mat;
    L = l;
    R = r;
  }
}

inline void solve() {
  cin >> n >> s >> t;
  for (int i = 0; i < n; ++i) {
    sum[i + 1] = sum[i] + (s[i] == t[i]);
  }
  mo = mm = sum[n];
  L = R = 1;
  for (int i = 0, mat; i < n; ++i) {
    // center at [i]
    mat = s[i] == t[i];
    for (int d = 1; ; ++d) {
      if (i - d < 0 || i + d >= n) break;
      mat += s[i - d] == t[i + d];
      mat += s[i + d] == t[i - d];
      update(mat, i - d, i + d);
    }
    if (!i) continue;
    // center at [i - 0.5]
    mat = 0;
    for (int d = 1; ; ++d) {
      if (i - d < 0 || i + d - 1 >= n) break;
      mat += s[i - d] == t[i + d - 1];
      mat += s[i + d - 1] == t[i - d];
      update(mat, i - d, i + d - 1);
    }
  }
  cout << mo << ' ' << mm << ' ' << L << ' ' << R << '\n';
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