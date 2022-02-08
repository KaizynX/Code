/*
 * @Author: Kaizyn
 * @Date: 2022-02-08 14:20:09
 * @LastEditTime: 2022-02-08 15:57:01
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
const int N = 1e2 + 7;

int n;
int a[N], b[N], rk[N];
multiset<int> gap;

inline bool solve() {
  gap.clear();
  gap.insert(INF);
  int sumb = 0;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
    rk[i] = i;
    sumb += b[i];
  }
  if (n == 2) return true;
  sort(rk + 1, rk + n + 1, [](int x, int y) {
    return pii{-a[x], b[x]} < pii{-a[y], b[y]};
  });
  for (int _ = 2, i, j; _ <= n; ++_) {
    i = rk[_];
    j = rk[_ - 1];
    gap.insert(a[j] - a[i]);
  }
  for (int _ = 2, i, j; _ <= n; ++_) {
    i = rk[_];
    j = rk[_ - 1];
    if (a[i] + sumb - b[i] > a[j]) return false;
    gap.erase(gap.find(a[j] - a[i]));
    if (b[i] > *gap.begin()) return false;
    gap.insert(a[j] - a[i]);
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