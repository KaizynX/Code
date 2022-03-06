/*
 * @Author: Kaizyn
 * @Date: 2022-02-27 20:28:24
 * @LastEditTime: 2022-02-27 20:36:18
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
const int N = 1e6 + 7;

int n;
int a[N];
int sum[N];
int base[] = {1,10,100,1000,10000,100000,1000000};

int bit(int x, int k) {
  return x / base[k] % 10;
}

int rev(int x) {
  int y = 0;
  for (int i = 0; i < 6; ++i) {
    y += (9 - bit(x, i)) * base[i];
  }
  return y;
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++sum[a[i]];
  }
  for (int i = 0; i < 6; ++i) {
    for (int val = 0; val < 1000000; ++val) {
      int b = bit(val, i);
      if (b == 0) continue;
      sum[val] += sum[val - base[i]];
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += sum[rev(a[i])];
    int flag = 1;
    for (int j = 0; j < 6; ++j) {
      int b = bit(a[i], j);
      if (b >= 5) flag = 0;
    }
    ans -= flag;
  }
  ans /= 2;
  cout << ans << '\n';
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