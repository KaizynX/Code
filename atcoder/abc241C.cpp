/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 19:58:45
 * @LastEditTime: 2022-02-26 20:48:35
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
const int N = 1e3 + 7;

int n;
char a[N][N];

inline bool solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i] + 1);
  }
  for (int i = 1; i <= n; ++i) {
    int cnt = 0;
    for (int l = 1, r = 1; l <= n; ++l) {
      while (r <= n && cnt + (a[i][r] == '.') <= 2) {
        cnt += a[i][r] == '.';
        ++r;
      }
      if (r - l >= 6) return true;
      cnt -= a[i][l] == '.';
    }
    cnt = 0;
    for (int l = 1, r = 1; l <= n; ++l) {
      while (r <= n && cnt + (a[r][i] == '.') <= 2) {
        cnt += a[r][i] == '.';
        ++r;
      }
      if (r - l >= 6) return true;
      cnt -= a[l][i] == '.';
    }
  }
  int cnt = 0;
  for (int l = 1, r = 1; l <= n; ++l) {
    while (r <= n && cnt + (a[r][r] == '.') <= 2) {
      cnt += a[r][r] == '.';
      ++r;
    }
    if (r - l >= 6) return true;
    cnt -= a[l][l] == '.';
  }
  cnt = 0;
  for (int l = 1, r = 1; l <= n; ++l) {
    while (r <= n && cnt + (a[r][n - r + 1] == '.') <= 2) {
      cnt += a[r][n - r + 1] == '.';
      ++r;
    }
    if (r - l >= 6) return true;
    cnt -= a[l][n - l + 1] == '.';
  }
  return false;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}