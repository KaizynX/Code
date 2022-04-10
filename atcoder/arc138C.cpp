/*
 * @Author: Kaizyn
 * @Date: 2022-04-09 21:10:53
 * @LastEditTime: 2022-04-09 21:31:24
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

int n, ansk;
ll anss;
int a[N], b[N];

void update(int k, ll s) {
  if (s > anss) {
    anss = s;
    ansk = k;
  }
}

inline void solve(int flag) {
  priority_queue<int, vector<int>, greater<int>> q;
  int m = 0;
  ll s = 0;
  for (int i = n; i; i -= 2) {
    q.push(a[i]);
    q.push(a[i - 1]);
    b[++m] = q.top();
    s += q.top();
    q.pop();
  }
  update(1 + flag, s);
  for (int i = 2; i < n; i += 2) {
    ;
    update(i + 1 + flag, s);
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  solve(0);
  rotate(a + 1, a + 2, a + n + 1);
  solve(1);
  cout << k << ' ' << s << '\n';
  return 0;
}