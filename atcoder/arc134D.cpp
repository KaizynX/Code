/*
 * @Author: Kaizyn
 * @Date: 2022-01-29 21:45:01
 * @LastEditTime: 2022-01-29 22:01:10
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
const int N = 2e5 + 7;

int n;
int a[N], t[N];
vector<int> ansl, ansr;

inline void solve() {
  cin >> n;
  int mn = 1e9;
  for (int i = 1; i <= 2 * n; ++i) {
    cin >> a[i];
    mn = min(mn, a[i]);
  }
  for (int i = 1; i <= 2 * n; ++i) {
    t[i] = (a[i] == mn) + t[i - 1];
  }
  int mx = 0, mp = 0, cur = 0;
  for (int i = 1, last = 0; i <= n; ++i) {
    if (a[i] != mn) continue;
    if (a[i + n] == mn) {
      cur += 2;
      last = i;
    } else {
      ;
    }
    int tmp = cur + t[n] - t[last];
    if (tmp > mx) {
      mx = tmp;
      mp = i;
    }
  }
  for (int i = 1; i <= mp; ++i) {
    if (a[i] != mn) continue;
    ansl.emplace_back(a[i]);
    ansr.emplace_back(a[i + n]);
  }
  for (int i = mp + 1; i <= n; ++i) {
    if (a[i] != mn) continue;
    mp = i;
    ansl.emplace_back(a[i]);
    ansr.emplace_back(a[i + n]);
  }
  for (int i = mp + 1; i <= n; ++i) {
  }
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