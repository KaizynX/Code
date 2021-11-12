/*
 * @Author: Kaizyn
 * @Date: 2021-11-12 19:02:59
 * @LastEditTime: 2021-11-12 19:12:22
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
const int N = 1e2+7;
const int M = 2e4+7;

inline bool is_prime(long long x) {
  if(x == 1) return false;
  if(x == 2 || x == 3) return true;
  if(x%6 != 1 && x%6 != 5) return false;
  for(long long i = 5; i*i <= x; i += 6)
    if(x%i == 0 || x%(i+2) == 0) return false;
  return true;
}

int n;
int a[N];

inline void solve() {
  cin >> n;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  if (is_prime(sum)) {
    int k = 0;
    for (int i = 1; i <= n; ++i) {
      if (!is_prime(sum-a[i])) {
        k = i;
        break;
      }
    }
    cout << n-1 << '\n';
    for (int i = 1; i <= n; ++i) {
      if (k != i) cout << i << ' ';
    }
    cout << '\n';
  } else {
    cout << n << '\n';
    for (int i = 1; i <= n; ++i) cout << i << " \n"[i==n];
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