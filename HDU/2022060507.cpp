/*
 * @Author: Kaizyn
 * @Date: 2022-06-04 19:11:01
 * @LastEditTime: 2022-06-04 20:40:34
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
// template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
const int N = 50 + 7;
const int A = 1e2 + 7;
const int M = N * A / 3;

int n;
int a[N];
int dp[M][M];

#ifdef DEBUG
void print(int sum) {
  cerr << "-----------\n";
  for (int i = 0; i <= sum; ++i) {
    for (int j = 0; j <= sum; ++j) {
      cerr << dp[i][j] << " \n"[j == sum];
    }
  }
  cerr << "-----------\n";
}
#endif

inline bool solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum % 3) return false;
  sum /= 3;
  for (int i = 0; i <= sum; ++i) {
    memset(dp[i], 0, sizeof(int) * (i + 1));
    // memset(dp[i], 0, sizeof(int) * (sum + 1));
  }
  dp[0][0] = 1;
  for (int k = 1; k <= n; ++k) {
    for (int i = sum; i >= 0; --i) {
      // for (int j = sum; j >= 0; --j) {
      for (int j = i; j >= 0; --j) {
        if (i >= a[k]) dp[i][j] |= dp[i - a[k]][j];
        if (j >= a[k]) dp[i][j] |= dp[i][j - a[k]];
      }
    }
    #ifdef DEBUG
    // print(sum);
    #endif
  }
  return dp[sum][sum];
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
  return 0;
}