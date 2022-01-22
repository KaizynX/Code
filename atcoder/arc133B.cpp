/*
 * @Author: Kaizyn
 * @Date: 2022-01-22 20:10:06
 * @LastEditTime: 2022-01-22 20:19:44
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

int n, m;
vector<int> seq;
vector<pii> arr;
int p[N], q[N];
int rp[N], rq[N];

int lcs() {
  seq.clear();
  for (pii pr : arr) {
    int x = pr.second;
    auto it = lower_bound(seq.begin(), seq.end(), x);
    if (it == seq.end()) seq.emplace_back(x);
    else *it = x;
  }
  return seq.size();
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    rp[p[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> q[i];
    rq[q[i]] = i;
  }
  int ans = 0;
  for (int k = 1; k <= n; ++k) {
    arr.clear();
    for (int i = 1; i * k <= n; ++i) {
      arr.emplace_back(rp[i], rq[i * k]);
    }
    sort(arr.begin(), arr.end());
    #ifdef DEBUG
    orzeach(arr);
    #endif
    ans = max(ans, lcs());
  }
  cout << ans << '\n';
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