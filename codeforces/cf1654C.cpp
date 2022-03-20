/*
 * @Author: Kaizyn
 * @Date: 2022-03-20 19:50:59
 * @LastEditTime: 2022-03-20 19:54:42
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
const int N = 2e5 + 7;

int n;
int a[N];

inline bool solve() {
  priority_queue<ll> q;
  cin >> n;
  ll sum = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  q.push(sum);
  sort(a + 1, a + n + 1);
  for (int i = n; i; --i) {
    while (q.top() > a[i]) {
      ll x = q.top();
      q.pop();
      q.push(x / 2);
      q.push(x - x / 2);
    }
    if (q.top() != a[i]) return false;
    q.pop();
  }
  return true;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "Yes" : "No") << '\n';
  }
  return 0;
}