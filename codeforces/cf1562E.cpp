/*
 * @Author: Kaizyn
 * @Date: 2021-08-26 23:05:53
 * @LastEditTime: 2021-08-27 00:26:38
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
const int N = 5e3+7;

int n;
int dp[N][N];
char s[N], ch[26][N];
int mx[26], val[26][N];

template <typename T>
void update(T &x, T y) {
  if (x < y) x = y;
}

void clear() {
  for (int i = 0; i < 26; ++i) {
    mx[i] = 0;
    ch[i][0] = 0;
  }
}

inline void solve() {
  clear();
  cin >> n >> (s+1);
  for (int i = 1, c; i <= n; ++i) {
    c = s[i]-'a';
    int mxv = 0;
    for (int j = 0; j < c; ++j) update(mxv, mx[j]);
    for (int j = i; j <= n; ++j) dp[i][j] = mxv+j-i+1;
    if (ch[c][0]) {
      int j, k;
      for (j = i; j <= n; ++j) {
        k = j-i+1;
        if (ch[c][k] != s[j]) break;
        update(dp[i][j], val[c][k]);
        update(val[c][k], dp[i][j]);
      }
      int z = j-i;
      if (ch[c][j-i+1] < s[j]) {
        for ( ; j <= n; ++j) {
          k = j-i+1;
          update(dp[i][j], mx[c]+k-z);
        }
      } else {
        for ( ; j <= n; ++j) {
          k = j-i+1;
          update(dp[i][j], val[c][z]+k-z);
          ch[c][k] = s[j];
          val[c][k] = dp[i][j];
        }
      }
    } else {
      ch[c][0] = 1;
      for (int j = i; j <= n; ++j) {
        ch[c][j-i+1] = s[j];
        val[c][j-i+1] = dp[i][j];
      }
    }
    for (int j = i; j <= n; ++j) update(mx[c], dp[i][j]);
    #ifdef DEBUG
    orzarr(dp[i]+1, n);
    #endif
  }
  cout << *max_element(mx, mx+26) << '\n';
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
/*
1
6
zazczb

9
*/