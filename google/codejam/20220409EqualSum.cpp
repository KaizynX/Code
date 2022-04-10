/*
 * @Author: Kaizyn
 * @Date: 2022-04-09 10:10:20
 * @LastEditTime: 2022-04-09 10:27:15
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
vector<int> a, b;

void print(vector<int> &v) {
  for (unsigned i = 0; i < v.size(); ++i) {
    if (i) cout << ' ';
    cout << v[i];
  }
  cout << endl;
}

inline void solve() {
  a.clear();
  b.clear();
  cin >> n;
  for (int i = 0; (1 << i) < 1000000000; ++i) {
    a.emplace_back(1 << i);
  }
  for (int i = 3; (int)a.size() < n; ++i) {
    if (__builtin_popcount(i) <= 1) continue;
    a.emplace_back(i);
  }
  print(a);
  b.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  ll suma = accumulate(a.begin(), a.end(), 0ll);
  ll sumb = accumulate(b.begin(), b.end(), 0ll);
  while (suma < sumb) {
    suma += b.back();
    sumb -= b.back();
    a.emplace_back(b.back());
    b.pop_back();
  }
  ll maxdis = 1ll << 31;
  while (suma - sumb >= maxdis) {
    sumb += a.back();
    suma -= a.back();
    b.emplace_back(a.back());
    a.pop_back();
  }
  ll dis = (suma - sumb) / 2;
  for (int i = 0; i < 30; ++i) {
    if ((dis >> i) & 1) {
      cout << (1 << i) << ' ';
    }
  }
  print(b);
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