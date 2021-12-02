/*
 * @Author: Kaizyn
 * @Date: 2021-11-28 22:50:43
 * @LastEditTime: 2021-11-28 23:09:19
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
const int N = 1e6+7;

struct Euler {
  vector<int> prime, check;
  int& operator [](const int &i) { return check[i]; }
  void init(int n) {
    prime.clear();
    check = vector<int>(n+1);
    for (int i = 2; i <= n; ++i) {
      if (!check[i]) prime.emplace_back(i), check[i] = i;
      for (const int &j : prime) {
        if (i*j > n) break;
        check[i*j] = j;
        if (i%j == 0) break;
      }
    }
  }
} E;

int n, e;
int a[N], cnt[N];
vector<int> sum[N];

inline void solve() {
  ll ans = 0;
  cin >> n >> e;
  for (int i = 0; i < e; ++i) sum[i] = {0};
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] = E[a[i]] == a[i];
    ans -= a[i];
    sum[i%e].emplace_back(sum[i%e].back()+a[i]);
  }
  #ifdef DEBUG
  orzarr(a, n);
  #endif
  for (int i = 0; i < e; ++i) {
    #ifdef DEBUG
    orzeach(sum[i]);
    #endif
    for (int j : sum[i]) {
      if (j) ans += cnt[j-1];
      ++cnt[j];
    } 
    for (int j : sum[i]) --cnt[j];
  }
  cout << ans << '\n';
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  E.init(1000000);
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}