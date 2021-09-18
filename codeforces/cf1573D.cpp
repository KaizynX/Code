/*
 * @Author: Kaizyn
 * @Date: 2021-09-18 23:13:59
 * @LastEditTime: 2021-09-19 00:07:43
 */
#include <bits/stdc++.h>

// #define DEBUG

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

inline void ope(int x) {
  ans.emplace_back(x);
  a[x] = a[x+1] = a[x+2] = a[x]^a[x+1]^a[x+2];
}

inline bool solve() {
  ans.clear();
  cin >> n;
  int sum = 0, L = n, R = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i]) {
      ++sum;
      L = min(L, i);
      R = max(R, i);
    }
  }
  if (sum == 0) return true;
  if (sum%2 || sum == n) return false;
  a[0] = a[n+1] = 1;
  sum = 0;
  for (int i = L, j; i <= n; i = j) {
    j = i+1;
    if (a[i] == 0) continue;
    while (j <= n && a[j] == 1) ++j;
    sum += j-i;
    if (j > R) break;
    if (sum&1) for (; j+1 <= n && a[j]+a[j+1] == 0; j += 2) ope(j-1);
  }
  #ifdef DEBUG
  orzarr(a+1, n);
  #endif
  for (int i = L, j; i <= n; i = j) {
    j = i+1;
    if (a[i] == 0) continue;
    while (j <= n && a[j] == 1) ++j;
    if ((j-i)%2 && j+1 <= n && a[j] == 0 && a[j+1] == 1) ope(--j);
    if (!a[i-1]) for (int k = i-1; k+2 < j; k += 2) ope(k);
    else if (!a[j]) for (int k = j; k-2 >= i; k -= 2) ope(k-2);
  #ifdef DEBUG
  orzarr(a+1, n);
  #endif
  }
  sum = 0;
  for (int i = 1; i <= n; ++i) sum += a[i];
  return sum == 0;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    if (solve()) {
      cout << "YES\n";
      cout << ans.size() << '\n';
      for (int i : ans) cout << i << ' ';
      if (ans.size()) cout << '\n';
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
/*
6

6
1 0 0 1 1 1
7
1 0 0 0 1 1 1
7
1 0 1 0 0 1 1
6
1 0 1 1 0 1
6
1 1 0 0 1 1
5
1 1 0 1 1
*/
/*
6
1 1 0 0 1 1
*/