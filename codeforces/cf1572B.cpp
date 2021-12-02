/*
 * @Author: Kaizyn
 * @Date: 2021-11-29 16:05:01
 * @LastEditTime: 2021-11-29 16:14:51
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
const int N = 2e5+7;

int n;
int a[N];
vector<int> ans;

void giao(int *i) {
  ans.emplace_back(i-a);
  int x = *i^*(i+1)^*(i+2);
  *i = *(i+1) = *(i+2) = x;
}

void work(int *l, int *r) {
  for (int *i = l; i+2 < r; i += 2) {
    giao(i);
  }
  for (int *i = r-2; i >= l; i -= 2) {
    if (*i) giao(i-1);
  }
}

inline void solve() {
  int spj = 0;
  ans.clear();
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    spj ^= a[i];
  }
  if (spj) return cout << "NO\n", void();
  if (n&1) {
    work(a+1, a+n+1);
    spj = 1;
  } else {
    for (int i = 1, s = 0; i <= n; ++i) {
      s ^= a[i];
      if (i%2 == 1 && s == 0) {
        spj = 1;
        work(a+1, a+i+1);
        work(a+i+1, a+n+1);
        break;
      }
    }
  }
  if (spj) {
    cout << "YES\n";
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
  } else {
    cout << "NO\n";
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