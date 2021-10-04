/*
 * @Author: Kaizyn
 * @Date: 2021-10-04 12:50:12
 * @LastEditTime: 2021-10-04 13:14:28
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
const int N = 2e3+7;

int n, m;
char a[N][N];
int col[N], row[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> (a[i]+1);
    row[i] = 0;
    for (int j = 1; j <= m/2; ++j) {
      if (a[i][j] != a[i][m-j+1]) break;
      ++row[i];
    }
  }
  for (int j = 1; j <= m; ++j) {
    col[j] = 0;
    for (int i = 1; i <= n/2; ++i) {
      if (a[i][j] != a[n-i+1][j]) break;
      ++col[j];
    }
  }
  // orzarr(row+1, n);
  // orzarr(col+1, m);
  int mnr = *min_element(row+1, row+n+1);
  int mnc = *min_element(col+1, col+m+1);
  // cout << mnr << ' ' << mnc << '\n';
  cout << min(mnr, m/2-1)*min(mnc, n/2-1) << '\n';
  // cout << (m/2-mnr)*(n/2-mnc) << '\n';
  /*
  int p = n/2, q = m/2;
  while (p && row[n/2-p+1] == m/2 && row[n/2+p] == m/2) --p;
  while (q && col[m/2-q+1] == n/2 && col[m/2+q] == n/2) --q;
  cout << (n/2-p+1)*(m/2-q+1) << '\n';
  */
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