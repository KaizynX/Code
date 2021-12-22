/*
 * @Author: Kaizyn
 * @Date: 2021-12-19 20:04:01
 * @LastEditTime: 2021-12-19 20:19:35
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
const int N = 100;

int n, m;
int a[N], b[N], c[N], d[N];
int to[N];

bool check(int i, int j) {
  return (a[i] == to[c[j]] && b[i] == to[d[j]])
      || (a[i] == to[d[j]] && b[i] == to[c[j]]);
}

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= m; ++i) {
    cin >> c[i] >> d[i];
  }
  iota(to + 1, to + n + 1, 1);
  int flag = 0;
  do {
    int tmp = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (check(i, j)) {
          ++tmp;
          break;
        }
      }
    }
    if (tmp == m) {
      flag = 1;
      break;
    }
  } while (next_permutation(to + 1, to + n + 1));
  cout << (flag ? "Yes" : "No") << '\n';
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