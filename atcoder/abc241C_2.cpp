/*
 * @Author: Kaizyn
 * @Date: 2022-02-26 20:50:35
 * @LastEditTime: 2022-02-26 21:48:58
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
    int cnt;
    for (int j = 1; j <= n; ++j) {
      if (j + 5 <= n) {
      cnt = 0;
      for (int k = j; k < j + 6; ++k) cnt += a[i][k] == '#';
      if (cnt >= 4) return true;
      cnt = 0;
      for (int k = j; k < j + 6; ++k) cnt += a[k][i] == '#';
      if (cnt >= 4) return true;
      }
      if (i + 5 <= n && j + 5 <= n) {
        cnt = 0;
        for (int k = 0; k <= 5; ++k) cnt += a[i + k][j + k] == '#';
        if (cnt >= 4) return true;
      }
      if (i - 5 >= 1 && j + 5 <= n) {
        cnt = 0;
        for (int k = 0; k <= 5; ++k) cnt += a[i - k][j + k] == '#';
        if (cnt >= 4) return true;
      }
    }
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